// src/server.hpp
//
//

#ifndef URPC_SERVER_HPP
#define URPC_SERVER_HPP

#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/noncopyable.hpp>
#include "zmq.hpp"


namespace urpc {

class Server : private boost::noncopyable {
  public:
    Server (const std::string &connection = "tcp://127.0.0.1:5555");
    ~Server ();
    void start ();
  private:
    std::string clientConn;
    std::string workerConn;   
    boost::shared_ptr<zmq::context_t> context;
    boost::shared_ptr<zmq::socket_t> clientSocket;
    boost::shared_ptr<zmq::socket_t> workerSocket;
    boost::thread_group workerPool;
    void worker ();
};


}
#endif // URPC_SERVER_HPP
