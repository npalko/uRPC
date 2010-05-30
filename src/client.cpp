// src/client.cpp
//
//


#include "client.hpp"

namespace urpc {

Client::Client () {
  std::vector<std::string> server;
  urpc::dns::getServer (server);
  
  context = boost::shared_ptr<zmq::context_t> (new zmq::context_t (1, 1));
  socket = boost::shared_ptr<zmq::socket_t> (new zmq::socket_t (*context, ZMQ_REQ));
  socket->connect ("tcp://127.0.0.1:5555");
  //socket->connect (server[0].c_str());
  // TODO: catch connect error, try next server, error out when out of list
  // TODO: AUTHENTICATE (Kerberos): request ticket here; throw if error
}
void Client::sendRequest (const std::string &service, int version, 
  const google::protobuf::Message &message) {
  urpc::Request query;
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
  urpc::Response response;
  zmq::message_t resultset;
 
  socket->recv (&resultset);
  //printf("recieved %d bytes\n", resultset.size());
  response.ParseFromArray (resultset.data(), resultset.size());
  message.ParseFromString (response.message());
}

}