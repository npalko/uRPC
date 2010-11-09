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
    Server (int, const std::string &, const std::string &);
    ~Server ();
    void start ();
  private:
    const int nIOThread;
    const std::string clientConn;
    const std::string workerConn;   
    boost::shared_ptr<zmq::context_t> context;
    boost::shared_ptr<zmq::socket_t> clientSocket;
    boost::shared_ptr<zmq::socket_t> workerSocket;
    boost::thread_group workerPool;
    void worker ();
};


}
#endif // URPC_SERVER_HPP
