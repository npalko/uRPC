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
#include <boost/noncopyable.hpp>
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


typedef std::map <std::string, boost::function<IService* (void)> > TServiceMap;
  
class Server : private boost::noncopyable {
  public:
    Server (const std::string &clientConn);
    ~Server ();
    /** Add a service for the server to serve
      * \param service object implementing IService
      */
    void addService (boost::function<IService* (void)>);
    /** Start serving
      */
    void start ();
  private:
    std::string clientConn;
    std::string workerConn;
    TServiceMap serviceMap;
    boost::shared_ptr<zmq::context_t> context;
    boost::shared_ptr<zmq::socket_t> clientSocket;
    boost::shared_ptr<zmq::socket_t> workerSocket;
    boost::thread_group workerPool;
    void worker (int);
    bool getRequest (zmq::socket_t &, pb::RequestEnvelope &);
    void sendReply (zmq::socket_t &, const pb::ReplyEnvelope &, bool);
};


}
#endif // URPC_SERVER_HPP
