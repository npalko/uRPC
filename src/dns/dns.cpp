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

std::string serverRecordToZMQString (const urpc::pb::Server_Record &record) {
  // return null-terminated string for zmq
  // tcp://host

  //switch record.protocol

  //return sprintf("%s://%s", record.name());
  return std::string("tcp://127.0.0.1:5555");

}
char *serverRecordToSpecification (const urpc::pb::Server_Record &record) {
  // _Service._Proto.Name   TTL   Class SRV Priority Weight Port Target
  // _sip._tcp.example.com. 86400 IN    SRV 0        5      5060 sipserver.example.com.

  //return sprintf("_%s._%s.%s.\t%d\t%s%d\t%d\t%d\t%s.",
  //  record.service(),
  //  record.priority(),
  //  record.weight(),
  //  record.port(),
  //  record.target());
  return "placeholder";
}
void getSRVRecord (urpc::pb::Server &server) {
  // populate server with SRV serverRecords
  // look up "_urpc._tcp"
  const int DNSPort = 53;
  
  
  
  
  std::vector<boost::asio::ip::address> DNSServer;
  urpc::dns::getServer (DNSServer); // platform-specific
  
  
  const int max_length = 100;
  char request[max_length];
  char reply[max_length];
  
  boost::asio::io_service io_service;
  
  std::vector<boost::asio::ip::address>::iterator addr = DNSServer.begin();
  for(; addr != DNSServer.end(); ++addr) {
    
    udp::endpoint destination (*addr, DNSPort);
    udp::socket socket (io_service, destination);
    socket.send_to (boost::asio::buffer (request, strlen(request)), destination);
    
    udp::endpoint sender_endpoint;
    size_t reply_length = socket.receive_from ( 
      boost::asio::buffer (reply, max_length), sender_endpoint);
    
  }





}

}
}
