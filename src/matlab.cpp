#include "Log.pb.h"
#include "uRPC.pb.h"
#include "zmq.hpp"

#include "mex.h"
#include "matlab.hpp"


EXPORTED_FUNCTION mxArray *request(const char *service, int version, 
  const mxArray *message)
{

  zmq::context_t context(1, 1);               // 1 application, 1 I/O thread
  zmq::socket_t socket(context, ZMQ_REQ);     // request-reply pattern
  socket.connect("tcp://127.0.0.1:5555");
 
  urpc::Request query;
  std::string queryString;
  query.set_service(service);
  query.set_version(version);
  query.set_message("this message");
  query.SerializeToString(&queryString);
  int length = strlen(queryString.c_str());
  zmq::message_t requestFrame(length);
  memcpy(requestFrame.data(), queryString.c_str(), length);
  socket.send(requestFrame);

  urpc::Response response;
  zmq::message_t resultset;
  socket.recv (&resultset);
  const char *resultset_string = (const char *) resultset.data();  
  response.ParseFromString(resultset_string);
  mexPrintf("got response: %s\n", response.message().c_str());

  mxArray *mxResponse = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
  return mxResponse;
}

// Small demos of functionality

EXPORTED_FUNCTION mxArray *zeros(mwSize m, mwSize n)
{
  // rough replica of MATLAB zeros() function
  
  mxArray *zeroArray = mxCreateNumericMatrix(m, n, mxDOUBLE_CLASS, mxREAL);
  return zeroArray;
}
