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

std::vector<boost::asio::ip::address> getServer() {

/*

resolver.h
-lresolv
libresolv


res_state
  nscount
  nsaddr_list[MAXNS]  - array of unsigned int




unsigned int  ipAddress = 167840383;
unsigned char octet[4]  = {0,0,0,0};
 
for (i=0; i<4; i++)
{
    octet[i] = ( ipAddress >> (i*8) ) & 0xFF;
}

printf("%d.%d.%d.%d\n",octet[3],octet[2],octet[1],octet[0]);



*/




  std::vector<boost::asio::ip::address> server;
  std::ofstream resolv;
  
  
  resolv.open("/etc/resolv.conf");
  
  
  
  
  
  resolv.close();
  
  
  return server;
}

