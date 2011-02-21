// src/client.cpp
//
//

#include "pb/Log.pb.h"
#include "pb/uRPC.pb.h"
#include "exception.hpp"
#include "kerberos/kerberos.hpp"
#include "client.hpp"

namespace urpc {	
  
Client::Client (const std::string &connection) : connection(connection) {	

  const int nIOThread = 1;
  urpc::kerberos::requestSessionTicket ();
  urpc::kerberos::submitSessionTicketToServer ();
  
  context.reset (new zmq::context_t (nIOThread));
  socket.reset (new zmq::socket_t (*context, ZMQ_REQ));
  socket->connect (connection.c_str());
}

void freeWire (void *data, void *hint) { free (data); }

void Client::sendRequest (const std::string &service, int version, 
                          const google::protobuf::Message &request, 
                          bool moreToFollow) {
  int sendFlag = moreToFollow ? ZMQ_SNDMORE : 0;
  urpc::pb::RequestEnvelope envelope;
  std::string requestString;
  
  request.SerializeToString (&requestString);
  envelope.set_service (service);
  envelope.set_version (version);
  envelope.set_request (requestString);

  char *wire = static_cast<char*> (malloc (envelope.ByteSize()));
  envelope.SerializeToArray (wire, envelope.ByteSize());
  zmq::message_t message (wire, envelope.ByteSize(), freeWire, NULL);

  socket->send (message, sendFlag);
}

bool Client::getReply (google::protobuf::Message &reply) {
  long long more;
  size_t sz = sizeof (more);
  urpc::pb::ReplyEnvelope envelope;
  zmq::message_t message;

  socket->recv (&message);
  socket->getsockopt (ZMQ_RCVMORE, &more, &sz);

  //printf("recieved %d bytes\n", message.size());
  envelope.ParseFromArray (message.data(), message.size());
  reply.ParseFromString (envelope.reply());
  return (more != 0);
}


}
