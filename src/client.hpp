#ifndef URPC_CLIENT_HPP
#define URPC_CLIENT_HPP

#include <string>
#include <boost/shared_ptr.hpp>
#include "pb/Log.pb.h"
#include "pb/uRPC.pb.h"
#include "zmq.hpp"
#include "dns/dns.hpp"
#include "exception.hpp"
#include "kerberos/kerberos.hpp"


namespace urpc {
// Blocking, single-threaded client. 
class Client {
  public:
    Client (const std::string &);
    void sendRequest (const std::string &, int, const google::protobuf::Message &);
    void getResponse (google::protobuf::Message &);
  private:
    boost::shared_ptr<zmq::context_t> context;
    boost::shared_ptr<zmq::socket_t> socket;
};


}
#endif // URPC_CLIENT_HPP
