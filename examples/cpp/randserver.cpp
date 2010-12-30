// examples/src/randserver.cpp
//
//

#include <cstdlib>
#include <string>
#include "server.hpp"
#include "randexample/randexample.pb.h"


class Rand : public urpc::IService {
  public:
    std::string getService () const { return "Rand"; }
    int getVersion () const { return 1; }
    void setRequest (const urpc::pb::RequestEnvelope &envelope, bool isMore) {
      randexample::Request request;
      
      request.ParseFromString (envelope.request());
      nMessage = request.nmessage ();
      nSample = request.nsample ();
      messageCount = nMessage;
    }
    bool getReply (urpc::pb::ReplyEnvelope &envelope) {
      
      randexample::Reply reply;
      for (int i = 0; i != nSample; ++i) {
        reply.add_r (static_cast<double> (rand ()));
      }
      
      std::string data;
      reply.SerializeToString (&data);
      envelope.set_reply (data);
      
      messageCount--;
      return messageCount > 0;
    }
  private:
    int nMessage;
    int nSample;
    int messageCount;
};


class SawTooth : public urpc::IService {
  public:
    std::string getService () const { return "SawTooth"; }
    int getVersion () const { return 1; }
    void setRequest (const urpc::pb::RequestEnvelope &envelope, bool isMore) {
      randexample::Request request;
    
      request.ParseFromString (envelope.request());
      nMessage = request.nmessage ();
      nSample = request.nsample ();
      messageCount = nMessage;
    }
    bool getReply (urpc::pb::ReplyEnvelope &envelope) {
    
      randexample::Reply reply;
      for (int i = 0; i != nSample; ++i) {
        reply.add_r (static_cast<double> (i));
      }
    
      std::string data;
      reply.SerializeToString (&data);
      envelope.set_reply (data);
    
      messageCount--;
      return messageCount > 0;
    }
  private:
    int nMessage;
    int nSample;
    int messageCount;
};



urpc::IService *fRand () { return new Rand; }


int main(int argc, char **argv) {

  urpc::Server server ("tcp://127.0.0.1:5555");
  
  server.addService (fRand);  
  server.start ();
}

