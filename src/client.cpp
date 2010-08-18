// src/client.cpp
//
//

#include "client.hpp"

namespace urpc {

Client::Client (const std::string &connection = urpc::dns::getConnection ()) {
  const int nIOThread = 1;
  urpc::kerberos::requestSessionTicket ();
  urpc::kerberos::submitSessionTicketToServer ();
  
  context = boost::shared_ptr<zmq::context_t> (new zmq::context_t(nIOThread));
  socket = boost::shared_ptr<zmq::socket_t> (new zmq::socket_t(*context, 
    ZMQ_REQ));
  socket->connect (connection.c_str());
}

void Client::sendRequest (const std::string &service, int version, 
  const google::protobuf::Message &message) {
  urpc::pb::Request query;
  std::string messageString, queryString;
  
  query.set_service (service);
  query.set_version (version);
  message.SerializeToString (&messageString);
  query.set_message (messageString);
  query.SerializeToString (&queryString);
  
  int length = strlen (queryString.c_str());
  zmq::message_t requestFrame (length);
  memcpy (requestFrame.data(), queryString.c_str(), length);
  socket->send (requestFrame);
}

void Client::getResponse (google::protobuf::Message &message) {
  urpc::pb::Response response;
  zmq::message_t resultset;
  
  socket->recv (&resultset);
  //printf("recieved %d bytes\n", resultset.size());
  response.ParseFromArray (resultset.data(), resultset.size());
  message.ParseFromString (response.message());
}


}
