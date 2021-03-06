#ifndef URPC_CLIENT_HPP
#define URPC_CLIENT_HPP

#include <string>
#include <boost/smart_ptr.hpp>
#include <google/protobuf/message.h>
#include "zmq.hpp"
#include "dns/dns.hpp"

namespace urpc {

class Client {
 public:
  Client();
  /** Connect to a service
    * \param connection ZMQ connection string
    * \param nIOThread number of ZMQ IO threads
    */ 
  int connect (const std::string &connection);
  /** Send a request to a service
    * \param service name of the service requested
    * \param version service version
    * \param request protobuf containing parameters of service requested
    * \param moreToFollow TRUE if is request is not the last part of a 
    * multi-part request. 
    */
  void sendRequest (const std::string &service,
                    int version,
                    const google::protobuf::Message &request,
                    bool moreToFollow = false);
  /** Get reply from a sent request
    * \param reply protobuf containing the service reply 
    * \return TRUE if additional messages exist after this reply, as in the
    * case of multi-part replies.
    */
  bool getReply (google::protobuf::Message &reply);
 private:
  const int nIOThread;
  boost::scoped_ptr<zmq::context_t> context;
  boost::scoped_ptr<zmq::socket_t> socket;
};

}
#endif // URPC_CLIENT_HPP
