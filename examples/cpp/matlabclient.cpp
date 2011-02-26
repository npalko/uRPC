// examples/cpp/matlabclient.cpp
//
//

#include "client.hpp"
#include "mex.h"
#include "matlabclient.hpp"
#include "randexample/randexample.pb.h"


EXPORTED_FUNCTION mxArray *request (const char * const service,
                                    int version,
                                    int nMessage,
                                    int nSample) {
  urpc::Client client("tcp://127.0.0.1:5555");
  randexample::Request request;
  randexample::Reply reply;
  
  request.set_nmessage (nMessage);
  request.set_nsample (nSample);
  client.sendRequest (service, version, request);
  
  mxArray *mxReply = mxCreateNumericMatrix (static_cast<mwSize>(nMessage),
    static_cast<mwSize>(nSample), mxDOUBLE_CLASS, mxREAL);
  double *out = mxGetPr (mxReply);
  
  client.getReply (reply);
  for (int i = 0; i < reply.r_size(); i++) {
    out[i] = reply.r (i);
  }
  return mxReply;
}

EXPORTED_FUNCTION mxArray *zeros (int m, int n) {
  mxArray *zeroArray = mxCreateNumericMatrix (static_cast<mwSize>(m), 
    static_cast<mwSize>(n), mxDOUBLE_CLASS, mxREAL);
  return zeroArray;
}
