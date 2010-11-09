// src/service.hpp
//
//

#include <string>

#include "pb/Log.pb.h"
#include "pb/uRPC.pb.h"


namespace urpc {
namespace service {

class IService {
  public:
    virtual ~IService ();
    virtual std::string getService ();
    virtual void processRequest (const urpc::pb::RequestEnvelope &, bool);
    virtual bool getReply (urpc::pb::ReplyEnvelope &);
};

class Unhandled : public IService {
  public:
    Unhandled ();
    ~Unhandled ();
    std::string getService ();
    void processRequest (const urpc::pb::RequestEnvelope &, bool);
    bool getReply (urpc::pb::ReplyEnvelope &);
};

class Blank : public IService {
  public:
    Blank ();
    ~Blank ();
    std::string getService ();
    void processRequest (const urpc::pb::RequestEnvelope &, bool);
    bool getReply (urpc::pb::ReplyEnvelope &);
  private:
    const std::string service;
};


IService factory (const std::string &);

} // service
} // urpc


