// 
// single threaded, nothing fancy

#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "dns.hpp"


std::vector<std::string> getSRV()
{


  boost::asio::ip::udp::resolver resolver(io_service);
  boost::asio::ip::udp::resolver::query query(argv[1], "dns");




}


  
  
  
