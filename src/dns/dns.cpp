// src/dns/dns.cpp
//
//

// http://www.boost.org/doc/libs/1_43_0/doc/html/boost_asio/example/echo/blocking_udp_echo_client.cpp


#include <cstdio>
#include "dns/dns.hpp"


namespace urpc {
namespace dns {

std::string getConnection() {

  std::vector<boost::asio::ip::address> hostDnsServer;
  urpc::pb::Server urpcSrv;
  std::string connection;

  urpc::dns::getServer (hostDnsServer);
  std::vector<boost::asio::ip::address>::const_iterator addr = hostDnsServer.begin();
  for(; addr != hostDnsServer.end(); ++addr) {
    urpc::dns::appendSrvRecordFromAddress (*addr, urpcSrv);
  }
  //connection = urpc::dns::getConnectionFromRecord (urpcSrv.record(0));
  connection = "tcp://120.0.0.1:5555";
  return connection;
}

std::string getConnectionFromRecord (const urpc::pb::Server_Record &record) {
  // "tcp://host:port"

  std::string connection;
  
  switch (record.protocol()) {
    case urpc::pb::Server_Record::TCP:
      connection += "tcp";
      break;
    case urpc::pb::Server_Record::UDP:
      connection += "udp";
      break;
  }
  connection += "://";
  connection += record.name();
  connection += ":";
  connection += boost::lexical_cast<std::string>((int) record.port());

  return connection;
}

void appendSrvRecordFromAddress (const boost::asio::ip::address &address, 
                           urpc::pb::Server &server)
{
  // lookup SRV records from server

  // address: DNS server
  // server: list of Server_Record's containing SRV entries corresponding to
  // _urpc._tcp
  
  
  // _Service._Proto.Name   TTL   Class SRV Priority Weight Port Target
  // _sip._tcp.example.com. 86400 IN    SRV 0        5      5060 sipserver.example.com.

  // Unix:     dig SRV _sip._tcp.example.com
  // Windows:  nslookup nslookup -q=SRV _sip._tls.microsoft.com






}

}
}
