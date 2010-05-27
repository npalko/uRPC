#ifndef URPC_CLIENT_HPP
#define URPC_CLIENT_HPP

#include "Log.pb.h"
#include "uRPC.pb.h"
#include "zmq.hpp"

#include "dns/dns.hpp"
#include "kerberos/kerberos.hpp"


namespace urpc
{
  // Blocking, single-threaded client. 
  class Client
  {
  public:
    Client ();
    ~Client ();
    void connect ();
    // pg 89 - slicing problem? will this need to be a templated function?
    void sendRequest (const std::string &, int, const google::protobuf::Message &);
    bool getResponse (google::protobuf::Message &);
    void close ();
  private:
    zmq::socket_t socket
  }


}
#endif // URPC_CLIENT_HPP