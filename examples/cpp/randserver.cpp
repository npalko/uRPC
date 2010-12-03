// examples/src/server.cpp
//
//

#include "server.hpp"
#include "randexample/randexample.pb.h"




class Rand : public urpc::IService {
  public:
    std::string getService () {
      return "Rand";
    }
    void processRequest (const urpc::pb::RequestEnvelope &requestEnvelope,
      bool isMore) {
    }
    bool getReply (urpc::pb::ReplyEnvelope &replyEnvelope) {
      return false;
    }
  private:
    
};

urpc::IService *fRand () { return new Rand; }



int main(int argc, char **argv) {

  urpc::Server server;
  
  server.addService (fRand);
  server.start ();
  
  return 0;
}

