#ifndef URPC_SERVER_HPP
#define URPC_SERVER_HPP

#include <cstdio>
#include <string>
#include <boost/shared_ptr.hpp>

#include "pb/Log.pb.h"
#include "pb/uRPC.pb.h"
#include "zmq.hpp"

#include "dns/dns.hpp"
#include "kerberos/kerberos.hpp"
#include "ldap/ldap.hpp"


namespace urpc {

class Server {
  public:
    Server ();
  private:
    boost::shared_ptr<zmq::context_t> context;
    boost::shared_ptr<zmq::socket_t> socket;
};


}
#endif // URPC_SERVER_HPP