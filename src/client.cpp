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
  const google::protobuf::Message &message, int flag) {
  urpc::pb::Request request;
  std::string messageString;
  std::string requestString;
  
  message.SerializeToString (&messageString);

  request.set_service (service);
  request.set_version (version);
  request.set_message (messageString);
  request.SerializeToString (&requestString);
  
  //zmq::message_t requestFrame (requestString.c_str(), requestString.length()), NULL, NULL);
  zmq::message_t requestFrame (requestString.length());
  memcpy (requestFrame.data(), requestString.c_str(), requestString.length());

  socket->send (requestFrame, flag);
}

bool Client::getReply (google::protobuf::Message &message) {
  urpc::pb::Reply reply;
  zmq::message_t resultset;
  long long more;
  size_t sz = sizeof (more);
  
  socket->recv (&resultset);
  socket->getsockopt (ZMQ_RCVMORE, &more, &sz);

  //printf("recieved %d bytes\n", resultset.size());
  reply.ParseFromArray (resultset.data(), resultset.size());
  message.ParseFromString (reply.message());
  return (more != 0);
}


}
