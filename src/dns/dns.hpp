// src/dns/dns.hpp
//
//

// Unix:     dig SRV _sip._tcp.example.com
// Windows:  nslookup -type=srv _sip._tcp.example.com




#ifndef URPC_DNS_HPP
#define URPC_DNS_HPP

#include <string>
#include <vector>
#include <boost/asio.hpp>

#include "pb/Log.pb.h"
#include "pb/uRPC.pb.h"


namespace urpc {
namespace dns {

char *serverRecordToZMQString (const urpc::pb::Server_Record &);
char *serverRecordToSpecification (const urpc::pb::Server_Record &);
void getSRVRecord (urpc::pb::Server &);
void getServer (std::vector<boost::asio::ip::address> &);  

}
}

#endif // URPC_DNS_HPP