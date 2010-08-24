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

/** Get ZMQ connection string of first SRV record returns from host DNS servers
  * \return ZMQ connection string
  */
std::string getConnection ();

/** Get ZMQ connection string from uRPC.Application protobuf
  * \param application uRPC.Application protobuf
  */
std::string getConnectionFromRecord (const urpc::pb::Application &record);

/** Look up _urpc._tcp SRV records on server and append to list
  * \param server address of server
  * \param list a listing of located uRPC SRV records
  */
void appendListFromServer (const boost::asio::ip::address &server, 
                           urpc::pb::ApplicationList &list);

/** Get DNS servers from host OS
  *\param list of DNS servers obtained from host OS
  */
void getServer (std::vector<boost::asio::ip::address> &server);

}
}

#endif // URPC_DNS_HPP