/*
Specification:

_Service._Proto.Name TTL Class SRV Priority Weight Port Target
_sip._tcp.example.com. 86400 IN SRV 0 5 5060 sipserver.example.com.

Verification:

Unix:     dig SRV _sip._tcp.example.com
Windows:  nslookup -type=srv _sip._tcp.example.com
*/


#ifndef URPC_DNS_HPP
#define URPC_DNS_HPP

namespace urpc 
{
  namespace dns 
  {
    class Server
    {
      public:
        Server ();
        Server (const std::string, const std::string, int);
        char *zmqConnectionString();
      private:
        std::string protocol;
        std::string address;
        int port;
    }
  
    std::vector<std::string> getDNSServer();
    std::vector<urpc::dns::Server> getuRPCServer();
  }
}

#endif // URPC_DNS_HPP