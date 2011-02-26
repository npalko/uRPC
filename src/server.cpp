// src/server.cpp
//
//

#include <iostream>
#include <boost/bind.hpp>
#include "dns/dns.hpp"
#include "kerberos/kerberos.hpp"
#include "ldap/ldap.hpp"

#include "server.hpp"


namespace urpc {

class NotImplemented : public IService {
/** The default IService used if a service is not found in the serviceMap.
  * We simply log the event and continue.
  */
 public:
  std::string getService () const { return "NotImplemented"; }
  int getVersion () const { return 0; }
  void setRequest (const pb::RequestEnvelope &envelope, bool isMore) {
    std::cout << envelope.service() << std::endl;
  }
  bool getReply (pb::ReplyEnvelope &envelope) { return false; }
};
  
  
Server::Server (const std::string &clientConn) : clientConn(clientConn) { 
  const int nIOThread = 1;
  workerConn = "inproc://workers";
  context.reset (new zmq::context_t (nIOThread));
  workerSocket.reset (new zmq::socket_t (*context, ZMQ_XREQ));
  clientSocket.reset (new zmq::socket_t (*context, ZMQ_XREQ));
}
void Server::addService (TService factory) {  
  boost::scoped_ptr<urpc::IService> service (factory ());
  serviceMap[service->getService ()] = factory;
}
void Server::start () {
  workerSocket->bind (workerConn.c_str ());
  clientSocket->bind (clientConn.c_str ());
  
  for (int i = 0; i != 3; ++i) {
    workerPool.add_thread (
      new boost::thread (&Server::worker, boost::ref(this), i));
  }	
  
  zmq::device (ZMQ_QUEUE, *clientSocket, *workerSocket); 
}
void Server::worker (int id) {
  using namespace boost;
  
  bool moreToReceive;
  bool moreToSend;
  pb::RequestEnvelope requestEnvelope;
  pb::ReplyEnvelope replyEnvelope;
  zmq::socket_t socket (*context, ZMQ_REP);
  
  socket.connect (workerConn.c_str ());
  
  while (true) {    
    moreToReceive = getRequest (socket, requestEnvelope);
    
    // creating appropriate service to handle request
    TServiceMap::iterator it = serviceMap.find (requestEnvelope.service ());
    bool notInMap = (it == serviceMap.end());
    scoped_ptr<IService> service (notInMap ? new NotImplemented : it->second ());  
    
    std::cout << id << ": " << requestEnvelope.service () << " -> " << 
      service->getService () << std::endl;
    service->setRequest (requestEnvelope, moreToReceive);
    requestEnvelope.Clear ();
    
    while (moreToReceive) {
      moreToReceive = getRequest (socket, requestEnvelope);
      service->setRequest (requestEnvelope, moreToReceive);
      requestEnvelope.Clear ();
    }
    
    do {
      moreToSend = service->getReply (replyEnvelope);
      sendReply (socket, replyEnvelope, moreToSend);
      replyEnvelope.Clear ();
    } while (moreToSend);
  }
}
bool Server::getRequest (zmq::socket_t &socket, pb::RequestEnvelope &envelope) {
  long long more;
  size_t sz = sizeof (more);
  zmq::message_t request;
  
  socket.recv (&request);
  socket.getsockopt (ZMQ_RCVMORE, &more, &sz);
  bool isAnotherRequest = more != 0;
  envelope.ParseFromArray (request.data(), request.size());
  
  return isAnotherRequest;
}
void freeWire (void *data, void *hint) { free (data); }
void Server::sendReply (zmq::socket_t &socket, 
                        const pb::ReplyEnvelope &envelope, 
                        bool moreToSend) {
  // We have a potential memory leak here in the event of a thread cancelation 
  // or exception, but this seems to be only way to interface with the ZMQ 
  // library while avoiding memory copying.
  
  char *wire = static_cast<char*> (malloc (envelope.ByteSize ()));
  envelope.SerializeToArray (wire, envelope.ByteSize());
  zmq::message_t reply (wire, envelope.ByteSize(), freeWire, NULL);
  
  int sendFlag = moreToSend ? ZMQ_SNDMORE : 0;
  socket.send (reply, sendFlag);
}

}
