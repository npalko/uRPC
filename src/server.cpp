// src/server.cpp
//
//


#include <boost/thread.hpp>

#include "pb/Log.pb.h"
#include "pb/uRPC.pb.h"
#include "dns/dns.hpp"
#include "kerberos/kerberos.hpp"
#include "ldap/ldap.hpp"

#include "server.hpp"


namespace urpc {

// goal is to write this so that we can plug in map from api



Server::Server () {

  context = boost::shared_ptr<zmq::context_t> (new zmq::context_t (nIOThread));
  workerSocket = boost::shared_ptr<zmq::socket_t> 
    (new zmq::socket_t (*context, ZMQ_XREQ));
  clientSocket = boost::shared_ptr<zmq::socket_t> 
    (new zmq::socket_t (*context, ZMQ_XREQ));
    
  workerSocket->bind (getWorkerConnectionString ().c_str ());
  clientSocket->bind (getClientConnectionString ().c_str ());


  // create a thread pool
  // each thread passed context, 
  // boost::thread threadName (boost::ref(x)


  // does this block?!?
  zmq::device (ZMQ_QUEUE, clientSocket.get (), workerSocket.get ()); 
}
Server::~Server () {

}
std::string Server::getClientConnectionString () {
  return "tcp://lo:5555";
}
std::string Server::getWorkerConnectionString () {
  return "inproc://workers";
}


}