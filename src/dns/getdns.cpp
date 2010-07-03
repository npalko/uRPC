// src/dns/getdns.cpp
//
//

#include <fstream>
#include <string>
#include <vector>
#include <boost/asio.hpp>

#include "dns/dns.hpp"


namespace urpc {
namespace dns {

void getAddress(std::vector<boost::asio::ip::address> &server) {


  std::ofstream resolv;
  
  
  resolv.open("/etc/resolv.conf");
  
  
  
  
  
  resolv.close();
  
  
  
}

