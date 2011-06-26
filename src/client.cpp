// src/client.cpp
//
//

#include "pb/Log.pb.h"
#include "pb/uRPC.pb.h"
#include "exception.hpp"
#include "kerberos/kerberos.hpp"
#include "client.hpp"

using std::string;
using google::protobuf::Message;

namespace urpc {	
  
Client::Client () : 
    nIOThread(1),
    context(new zmq::context_t (nIOThread)),
    socket(new zmq::socket_t (*context, ZMQ_REQ)) {
}
int Client::connect (const std::string &connection) {
  socket->connect (connection.c_str());
  return 0;
}
void freeWire (void *data, void *hint) { free (data); }
void Client::sendRequest (const string &service, 
                          int version, 
                          const Message &request, 
                          bool moreToFollow) {
  /*
  struct freeWire {
    void static operator()(void *data, void *hint) {
      free (data);
    }
  };
  */
  
  string serializedRequest;
  request.SerializeToString (&serializedRequest);
  
  pb::RequestEnvelope envelope;
  envelope.set_service (service);
  envelope.set_version (version);
  envelope.set_request (serializedRequest);
  
  char *wire = static_cast<char*> (malloc (envelope.ByteSize()));
  envelope.SerializeToArray (wire, envelope.ByteSize());
  zmq::message_t message (wire, envelope.ByteSize(), freeWire, NULL);
  
  int sendFlag = moreToFollow ? ZMQ_SNDMORE : 0;
  socket->send (message, sendFlag);
}
bool Client::getReply (Message &reply) {
  long long more;
  size_t sz = sizeof (more);
  zmq::message_t message;
  socket->recv (&message);
  socket->getsockopt (ZMQ_RCVMORE, &more, &sz);
  bool isMoreToProcess = more != 0;
  //printf("recieved %d bytes\n", message.size());
  
  pb::ReplyEnvelope envelope;
  envelope.ParseFromArray (message.data(), message.size());
  reply.ParseFromString (envelope.reply());
  
  return isMoreToProcess;
}

}
