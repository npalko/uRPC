/*
Specification:

_Service._Proto.Name    TTL      Class  SRV  Priority Weight  Port  Target
_sip._tcp.example.com.  86400  IN   SRV 0       5             5060  sipserver.example.com.

Verification:

Unix:     dig SRV _sip._tcp.example.com
Windows:  nslookup -type=srv _sip._tcp.example.com

array of servers
put on stack



*/


#ifndef URPC_DNS_HPP
#define URPC_DNS_HPP

namespace urpc {
namespace dns {
//class Server
//{
//  public:
//    Server ();
//    Server (const std::string, const std::string, int);
//    char *zmqConnectionString();
//  private:


//  service: the symbolic name of the desired service.
//protocal: the transport protocol of the desired service; this is usually either TCP or UDP.
//name: the domain name for which this record is valid.
//ttl: standard DNS time to live field.
//priority: the priority of the target host, lower value means more preferred.
//weight: A relative weight for records with the same priority.
//port: the TCP or UDP port on which the service is to be found.
//target: the canonical hostname of the machine providing the service.
//    std::string protocol;
//    int priority;
//    int weight;
//    int port;
//    std::string target;
//};

void getDNSServer(std::vector<std::string> &);
void getServer(std::vector<std::string> &);


}
}

#endif // URPC_DNS_HPP