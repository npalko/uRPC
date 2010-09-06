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
    
    
  // bare minimum:
  //  create threadpool in constructor, cancell all threads in destructor
  

  // create a thread pool
  // each thread passed context, 
  // boost::thread threadName (boost::ref(x)
  
    
  workerSocket->bind (getWorkerConnectionString ().c_str ());
  clientSocket->bind (getClientConnectionString ().c_str ());
  
  // this should be put into its own thread so we can
  zmq::device (ZMQ_QUEUE, clientSocket.get (), workerSocket.get ()); 

  // map<std::string, function> make sense? 
  //  should this map be passed to server on construction?
  //  constructor with many parameters an ok form?
  // are multipart requests and responses handeled by the zmq framework?
  // 


  
}
std::string Server::getClientConnectionString () const {
  return "tcp://lo:5555";
}
std::string Server::getWorkerConnectionString () const {
  return "inproc://workers";
}


}