/*
  TODO:
    * keep request, response as part of client objet - don't recreate objects
      each time
    * zero-copy!
    * logging: be able to redirect to different log output (say mexprintf)
    

*/

#include "client.hpp"

namespace urpc {
Client::Client () {
}
void Client::connect () {
  std::vector<std::string> server;
  urpc::dns::getServer (server);
  
  std::vector<std::string>::iterator i = server.begin();
  for(; i != server.end(); ++i)
    std::cout << *i << std::endl;
  
  // TODO: AUTHENTICATE (Kerberos): request ticket here; throw if error
  zmq::context_t context(1,1); // 1 application, 1 I/O thread
  socket = &zmq::socket_t(context, ZMQ_REQ);
  socket->connect ("tcp://127.0.0.1:5555");
  printf("connext ok\n");
  //socket->connect (server[0].c_str());
  // TODO: catch connect error, try next server, error out when out of list
}
void Client::sendRequest (const std::string &service, int version, 
  const google::protobuf::Message &message) {
  urpc::Request query;
  std::string messageString, queryString;
  
  message.SerializeToString(&messageString);
  query.set_service(service);
  query.set_version(version);
  query.set_message(messageString);
  query.SerializeToString(&queryString);

  int length = strlen(queryString.c_str());
  zmq::message_t requestFrame(length);
  memcpy(requestFrame.data(), queryString.c_str(), length);
  socket->send(requestFrame);
}
bool Client::getResponse (google::protobuf::Message &message) {
  urpc::Response response;
  zmq::message_t resultset;
  
  socket->recv (&resultset);
  response.ParseFromString((const char *) resultset.data());
  // throw:
  //    AUTHORIZE error: not allowed to make api request
  //    poorly formed request
  //    connection timeout error?
  
  message.ParseFromString(response.message());
  
  return true;
}
void Client::close () {
}
}