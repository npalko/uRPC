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
    std::string getService () { return "NotImplemented"; }
    void processRequest (const urpc::pb::RequestEnvelope &request, 
      bool isMore) {
      
      std::cout << request.service() << std::endl;
    }
    bool getReply (urpc::pb::ReplyEnvelope &) {
      return false;
    }
};  

urpc::IService *fNotImplemented () { return new NotImplemented; }
  

// Server
  
  
void deleteEnvelope (void *data, void *hint) { free (data); }

Server::Server () { 
    
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
void Server::addService (urpc::IService *pIService) {  
  
  boost::shared_ptr<urpc::IService> service (pIService);
  serviceMap[service->getService()] = service;
}
void Server::removeService (const std::string &serviceLabel) {
  
  // TODO
}
std::vector<std::string> Server::getServiceList () const {
  
}  
void Server::start() {
  
  workerSocket->bind (workerConn.c_str ());
  clientSocket->bind (clientConn.c_str ());
  
  for (int i=1; i != 4; ++i) {
    workerPool.add_thread (
      new boost::thread(&urpc::Server::worker, boost::ref(this)));
  }	
  
  zmq::device (ZMQ_QUEUE, *clientSocket, *workerSocket); 
}
void Server::worker () {
  bool moreToReceive, moreToSend;
  long long more;
  size_t sz = sizeof (more);
  
  urpc::pb::RequestEnvelope requestEnvelope;
  urpc::pb::ReplyEnvelope replyEnvelope;
  
  boost::shared_ptr<urpc::NotImplemented> 
    serviceNotImplemented(new NotImplemented);
  
  zmq::socket_t socket (*context, ZMQ_REP);
  socket.connect (workerConn.c_str ());

  while (true) {
    
    zmq::message_t request;
    socket.recv (&request);
    socket.getsockopt (ZMQ_RCVMORE, &more, &sz);
    moreToReceive = (more != 0);
    requestEnvelope.Clear ();
    requestEnvelope.ParseFromArray (request.data(), request.size());
    
    TServiceMap::iterator it = serviceMap.find (requestEnvelope.service());
    bool serviceNotInMap = (it == serviceMap.end());
      
    // THIS IS INCORRECT !!! Need to create a new object to handle each
    // request
    // construct object to handle each request
    
    
    boost::shared_ptr<urpc::IService> sv = 
      serviceNotInMap ? serviceNotImplemented : it->second;  
      
    sv->processRequest (requestEnvelope, moreToReceive);
    replyEnvelope.Clear ();
    moreToSend = sv->getReply (replyEnvelope);
    int sendFlag = moreToSend ? ZMQ_SNDMORE : 0;

    char *wireEnvelope = static_cast<char*> (malloc(replyEnvelope.ByteSize()));
    replyEnvelope.SerializeToArray(wireEnvelope, replyEnvelope.ByteSize());
    zmq::message_t reply 
      (wireEnvelope, replyEnvelope.ByteSize(), deleteEnvelope, NULL);
    socket.send (reply, sendFlag);
  }
}

}
