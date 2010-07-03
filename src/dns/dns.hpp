// src/dns/dns.hpp
//
//

// _Service._Proto.Name   TTL   Class SRV Priority Weight Port Target
// _sip._tcp.example.com. 86400 IN    SRV 0        5      5060 sipserver.example.com.

// Unix:     dig SRV _sip._tcp.example.com
// Windows:  nslookup -type=srv _sip._tcp.example.com




#ifndef URPC_DNS_HPP
#define URPC_DNS_HPP

#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>

#include "pb/Log.pb.h"
#include "pb/uRPC.pb.h"


namespace urpc {
namespace dns {

void getAddress (std::vector<boost::asio::ip::address> &);                         
void getRecordFromAddress (const boost::asio::ip::address &, urpc::pb::Server &);
std::string getConnectionStringFromRecord(const urpc::pb::Server_Record &);

}
}

#endif // URPC_DNS_HPP