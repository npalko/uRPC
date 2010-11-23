// src/server.cpp
//
//


#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>

#include "pb/Log.pb.h"
#include "pb/uRPC.pb.h"
#include "dns/dns.hpp"
#include "kerberos/kerberos.hpp"
#include "ldap/ldap.hpp"
#include "service.hpp"

#include "server.hpp"

namespace urpc {

void deleteEnvelope (void *data, void *hint) {
  free(data);
}

Server::Server (const std::string &clientConn_) { 

  const int nIOThread = 1;
  workerConn = "inproc://workers";
  clientConn = clientConn_;

  context = boost::shared_ptr<zmq::context_t> (new zmq::context_t (nIOThread));
  workerSocket = boost::shared_ptr<zmq::socket_t> 
    (new zmq::socket_t (*context, ZMQ_XREQ));
  clientSocket = boost::shared_ptr<zmq::socket_t> 
    (new zmq::socket_t (*context, ZMQ_XREQ));
    
  for (int i=0; i != 4; ++i) {
    workerPool.add_thread (
      new boost::thread(&urpc::Server::worker, boost::ref(this)));
  }
}
Server::~Server () {

}
void Server::start() {
  workerSocket->bind (workerConn.c_str ());
  clientSocket->bind (clientConn.c_str ());
  zmq::device (ZMQ_QUEUE, clientSocket.get (), workerSocket.get ()); 
}
void Server::worker () {
  bool moreToReceive, moreToSend;
  long long more;
  size_t sz = sizeof (more);
  
  urpc::pb::RequestEnvelope requestEnvelope;
  urpc::pb::ReplyEnvelope replyEnvelope;
  
  zmq::socket_t socket (*context, ZMQ_REP);
  socket.connect (workerConn.c_str ());

  while (true) {
    
    
    zmq::message_t request;
    socket.recv (&request);
    socket.getsockopt (ZMQ_RCVMORE, &more, &sz);
    moreToReceive = (more != 0);
    requestEnvelope.Clear ();
    requestEnvelope.ParseFromArray (request.data(), request.size());
      
    urpc::service::IService sv =
      urpc::service::factory (requestEnvelope.service() );
    sv.processRequest (requestEnvelope, moreToReceive);

    
    replyEnvelope.Clear ();
    moreToSend = sv.getReply (replyEnvelope);
    int sendFlag = moreToSend ? ZMQ_SNDMORE : 0;

    char *wireEnvelope = (char*) malloc(replyEnvelope.ByteSize());
    replyEnvelope.SerializeToArray(wireEnvelope, replyEnvelope.ByteSize());
    zmq::message_t reply (wireEnvelope, replyEnvelope.ByteSize(), 
      deleteEnvelope, NULL);
    socket.send (reply, sendFlag);
 
  }
}

}
