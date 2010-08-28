// src/server.hpp
//
//

#ifndef URPC_SERVER_HPP
#define URPC_SERVER_HPP

#include <string>
#include <boost/shared_ptr.hpp>
#include "zmq.hpp"


namespace urpc {

class Server {
  public:
    Server ();
    ~Server ();
  private:
    static const int nIOThread = 1;
    std::string getClientConnectionString () const;
    std::string getWorkerConnectionString () const;
    boost::shared_ptr<zmq::context_t> context;
    boost::shared_ptr<zmq::socket_t> clientSocket;
    boost::shared_ptr<zmq::socket_t> workerSocket;
};


}
#endif // URPC_SERVER_HPP
