// src/server.hpp
//
//

#ifndef URPC_SERVER_HPP
#define URPC_SERVER_HPP

#include <map>
#include <string>
#include <vector>
#include <boost/function.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/thread.hpp>
#include "zmq.hpp"
#include "pb/Log.pb.h"
#include "pb/uRPC.pb.h"


namespace urpc {
  
class IService {
  /** Every service offered by Server implements IService. An IService exists
    * over the lifetime of a single multi-part request/reply pattern, allowing 
    * you to store the state of the multi-part response in the IService if 
    * desired.
    */
  public:
    virtual ~IService () {}
    virtual std::string getService () const = 0;
    virtual int getVersion () const = 0;
    /** Called multiple times in the event of a multi-part request.
      * \param envelope
      * \param isMore TRUE if setRequest will be called again in multi-part 
      *   request
      */
    virtual void setRequest (const pb::RequestEnvelope &envelope, 
                             bool isMore) = 0;
    /** Called multiple times in the event of a multi-part response.
      * \param envelope
      * \return TRUE if more data is available in a multi-part response
      */
    virtual bool getReply (pb::ReplyEnvelope &envelope) = 0;
};

  
class Server {
  public:
    typedef boost::function<IService* (void)> TService;
    Server (const std::string &clientConn);
    ~Server ();
    /** Add a service for the server to serve
      * \param service object implementing IService
      */
    void addService (TService);
    /** Start serving
      */
    void start ();
  private:
    typedef std::map <std::string, TService> TServiceMap;
    std::string clientConn;
    std::string workerConn;
    TServiceMap serviceMap;
    boost::scoped_ptr<zmq::context_t> context;
    boost::scoped_ptr<zmq::socket_t> clientSocket;
    boost::scoped_ptr<zmq::socket_t> workerSocket;
    boost::thread_group workerPool;
    void worker (int);
    bool getRequest (zmq::socket_t &, pb::RequestEnvelope &);
    void sendReply (zmq::socket_t &, const pb::ReplyEnvelope &, bool);
};


}
#endif // URPC_SERVER_HPP
