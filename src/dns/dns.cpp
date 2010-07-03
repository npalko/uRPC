// src/dns/dns.cpp
//
//

// http://www.boost.org/doc/libs/1_43_0/doc/html/boost_asio/example/echo/blocking_udp_echo_client.cpp


#include <cstdio>
#include <string>

#include "dns/dns.hpp"



namespace urpc {
namespace dns {

using boost::asio::ip::udp;

void getRecordFromAddress (const boost::asio::ip::address &address, 
                           urpc::pb::Server &server)
{
  // append Server_Record to server based on SRV records obtained from DNS 
  // server at address

  // look up "_urpc._tcp"

  const int DNSPort = 53;


  const int max_length = 100;
  char request[max_length];
  char reply[max_length];
  
  boost::asio::io_service io_service;
  udp::endpoint destination (address, DNSPort);
  udp::socket socket (io_service, destination);
  
  socket.send_to (boost::asio::buffer (request, strlen(request)), destination);
    
  udp::endpoint sender_endpoint;
  size_t reply_length = socket.receive_from ( 
    boost::asio::buffer (reply, max_length), sender_endpoint);
    
}
std::string getConnectionStringFromRecord (const urpc::pb::Server_Record &record) {
  // tcp://host:port

  std::string connection;
  
  switch (record.protocol()) {
    case urpc::pb::Server_Record::TCP:
      connection += "tcp";
      break;
    case urpc::pb::Server_Record::UDP:
      connection += "udp";
      break;
  }
  connection += "://";
  connection += record.name();
  connection += ":";
  connection += boost::lexical_cast<std::string>((int) record.port());

  return connection;
}



}
}
