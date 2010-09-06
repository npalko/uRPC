// src/dns/getdns-osx.cpp
//
//

#include <vector>
#include <boost/asio.hpp>

#include "dns/dns.hpp"


namespace urpc {
namespace dns {

std::vector<boost::asio::ip::address> getServer() {

  std::vector<boost::asio::ip::address> server;  
  return server;
}


}
}