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
  context.reset (new zmq::context_t (nIOThread));
  socket.reset (new zmq::socket_t (*context, ZMQ_REQ));
  socket->connect (connection.c_str());
}
void freeWire (void *data, void *hint) { free (data); }
void Client::sendRequest (const std::string &service, 
                          int version, 
                          const google::protobuf::Message &request, 
                          bool moreToFollow) {
  std::string serializedRequest;
  request.SerializeToString (&serializedRequest);
  
  urpc::pb::RequestEnvelope envelope;
  envelope.set_service (service);
  envelope.set_version (version);
  envelope.set_request (serializedRequest);
  char *wire = static_cast<char*> (malloc (envelope.ByteSize()));
  envelope.SerializeToArray (wire, envelope.ByteSize());
  zmq::message_t message (wire, envelope.ByteSize(), freeWire, NULL);
  
  int sendFlag = moreToFollow ? ZMQ_SNDMORE : 0;
  socket->send (message, sendFlag);
}
bool Client::getReply (google::protobuf::Message &reply) {
  long long more;
  size_t sz = sizeof (more);
  zmq::message_t message;
  socket->recv (&message);
  socket->getsockopt (ZMQ_RCVMORE, &more, &sz);
  bool isMoreToProcess = more != 0;
  //printf("recieved %d bytes\n", message.size());
  
  urpc::pb::ReplyEnvelope envelope;
  envelope.ParseFromArray (message.data(), message.size());
  reply.ParseFromString (envelope.reply());
  
  return isMoreToProcess;
}

}
