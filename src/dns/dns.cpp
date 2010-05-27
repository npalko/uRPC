// 
// single threaded, nothing fancy

#include <string>
#include <vector>
#include <boost/asio.hpp>

#include "dns.hpp"

std::vector<std::string> getsrv()
{
  std::vector<std::string> srv = getdns()


  //boost::asio::ip::udp::resolver resolver(io_service);
  //boost::asio::ip::udp::resolver::query query(argv[1], "dns");



  return srv;
}


  
  
  
