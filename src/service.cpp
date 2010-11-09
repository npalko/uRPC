// src/service.cpp
//
//

#include "service.hpp"



namespace urpc {
namespace service {

Unhandled::Unhandled () {}
Unhandled::~Unhandled () {}
std::string Unhandled::getService () {
  return "";
}
void Unhandled::processRequest (const urpc::pb::RequestEnvelope &request, 
  bool isMore) {
  // log our unhandled request
}
bool Unhandled::getReply (urpc::pb::ReplyEnvelope &reply) {
  // set error - unhandled request
  return false; // no more to send
}


Blank::Blank () : service("Blank") {}
Blank::~Blank () {}
std::string Blank::getService () {
  return service;
}
void Blank::processRequest (const urpc::pb::RequestEnvelope &request, 
  bool isMore) {
}
bool Blank::getReply (urpc::pb::ReplyEnvelope &reply) {
  return false;
}


IService factory (const std::string &service) {

  if (service.compare("Blank") == 0) {
    return Blank ();
  } else {
    return Unhandled ();
  }
}

} // service
} // urpc

