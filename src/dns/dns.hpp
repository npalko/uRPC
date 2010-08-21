// src/dns/dns.hpp
//
//

#ifndef URPC_DNS_HPP
#define URPC_DNS_HPP

#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>

#include "pb/Log.pb.h"
#include "pb/uRPC.pb.h"

#include "exception.hpp"


namespace urpc {
namespace dns {

std::string getConnection ();
std::string getConnectionFromRecord (const urpc::pb::Server_Record &);
void appendSrvRecordFromAddress (const boost::asio::ip::address &, urpc::pb::Server &);
void getServer (std::vector<boost::asio::ip::address> &);

}
}

#endif // URPC_DNS_HPP