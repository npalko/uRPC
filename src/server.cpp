// src/server.cpp
//
//

#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
#include "dns/dns.hpp"
#include "kerberos/kerberos.hpp"
#include "ldap/ldap.hpp"

#include "server.hpp"

namespace urpc {
  
  
// NotImplemented. This is only IService defined by default to exist in the 
// service map. We simply log the error that the service wasn't found and 
// continue on our merry way.

class NotImplemented : public IService {
  public:
    std::string getService () const { return "NotImplemented"; }
    int getVersion ()  const { return 0; }
    void setRequest (const pb::RequestEnvelope &request, bool isMore) {
      
      std::cout << request.service() << std::endl;
    }
    bool getReply (pb::ReplyEnvelope &) {
      return false;
    }
};  
  

// Server
  
  
void freeWire (void *data, void *hint) { free (data); }

Server::Server (const std::string &foo) { 
    
  const int nIOThread = 1;
  workerConn = "inproc://workers";
  clientConn = "tcp://127.0.0.1:5555";

  context = boost::shared_ptr<zmq::context_t> (new zmq::context_t (nIOThread));
  workerSocket = boost::shared_ptr<zmq::socket_t> 
    (new zmq::socket_t (*context, ZMQ_XREQ));
  clientSocket = boost::shared_ptr<zmq::socket_t> 
    (new zmq::socket_t (*context, ZMQ_XREQ));
  
}
Server::~Server () {
  
  // TODO: kill threads here
}
void Server::addService (boost::function<IService* (void)> factory) {  
  
  boost::shared_ptr<urpc::IService> service (factory ());
  serviceMap [service->getService ()] = factory;
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
  
  bool moreToReceive;
  bool moreToSend;
  pb::RequestEnvelope requestEnvelope;
  pb::ReplyEnvelope replyEnvelope;
  zmq::socket_t socket (*context, ZMQ_REP);
  
  socket.connect (workerConn.c_str ());

  while (true) {    
    moreToReceive = getRequest (socket, requestEnvelope);

    // handle request by creating appropriate service
    TServiceMap::iterator it = serviceMap.find (requestEnvelope.service ());
    bool serviceNotInMap = (it == serviceMap.end());
    boost::shared_ptr<urpc::IService> service 
      (serviceNotInMap ? new NotImplemented : it->second ());  
    
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
bool Server::getRequest (zmq::socket_t &socket, 
                         pb::RequestEnvelope &envelope) {
 
  long long more;
  size_t sz = sizeof (more);
  
  zmq::message_t request;
  socket.recv (&request);
  socket.getsockopt (ZMQ_RCVMORE, &more, &sz);
  bool moreToReceive = (more != 0);
  envelope.ParseFromArray (request.data(), request.size());
  
  return moreToReceive;
}
void Server::sendReply (zmq::socket_t &socket, 
                        const pb::ReplyEnvelope &envelope, bool moreToSend) {
  
  char *wire = static_cast<char*> (malloc (envelope.ByteSize ()));
  envelope.SerializeToArray (wire, envelope.ByteSize());
  zmq::message_t reply (wire, envelope.ByteSize(), freeWire, NULL);
  
  int sendFlag = moreToSend ? ZMQ_SNDMORE : 0;
  socket.send (reply, sendFlag);
}

}
