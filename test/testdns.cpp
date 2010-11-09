#include <iostream>
#include "dns/dns.hpp"


int main (int argc, char **argv) {

  std::cout << "Name Servers:" << std::endl;

  std::vector<boost::asio::ip::address> dnsServer = urpc::dns::getServer ();
  std::vector<boost::asio::ip::address>::iterator addr = dnsServer.begin();
  for(; addr != dnsServer.end(); ++addr) {
    std::cout << *addr << std::endl;
  }

  
  
  

  return 0;
}