// src/server.hpp
//
//

#ifndef URPC_SERVER_HPP
#define URPC_SERVER_HPP

#include <map>
#include <string>
#include <vector>
#include <boost/smart_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/noncopyable.hpp>
#include "zmq.hpp"
#include "pb/Log.pb.h"
#include "pb/uRPC.pb.h"


namespace urpc {
  
class IService {
  public:
    virtual ~IService () {}
    virtual std::string getService () = 0;
    virtual void processRequest (const urpc::pb::RequestEnvelope &, bool) = 0;
    virtual bool getReply (urpc::pb::ReplyEnvelope &) = 0;
};


//typedef std::map <std::string, urpc::IService (*)()> TServiceMap;
typedef std::map <std::string, boost::shared_ptr<urpc::IService> > TServiceMap;
  
class Server : private boost::noncopyable {
  public:
    Server ();
    //Server (const std::string &connection = "tcp://127.0.0.1:5555");
    ~Server ();
  
    /** Add a service for the server to server
      * \param service object implementing IService
      * \return TRUE on successfull addition of service
      */
    //void addService (boost::shared_ptr<urpc::IService> service);
    void addService (urpc::IService *pIService);
  
    /** Remove a service currently loaded on the server
      * \param serviceLabel string representing the service
      */
    void removeService (const std::string &serviceLabel );
    
    /** Return a list of services currently offered by the server 
      * \return list of services
      */
    std::vector<std::string> getServiceList () const;
    void start ();
  private:
    std::string clientConn;
    std::string workerConn;
    TServiceMap serviceMap;
    boost::shared_ptr<zmq::context_t> context;
    boost::shared_ptr<zmq::socket_t> clientSocket;
    boost::shared_ptr<zmq::socket_t> workerSocket;
    boost::thread_group workerPool;
    void worker ();
};


}
#endif // URPC_SERVER_HPP
