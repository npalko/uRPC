// 
// single threaded, nothing fancy

#include <string>
#include <vector>
//#include <boost/asio.hpp>

#include "dns.hpp"

namespace urpc {
namespace dns {

void getServer(std::vector<std::string> &server) {

  
  urpc::dns::getDNSServer(server);


  //boost::asio::ip::udp::resolver resolver(io_service);
  //boost::asio::ip::udp::resolver::query query(argv[1], "dns");


}

}
}
