// examples/cpp/matlabclient.cpp
//
//

#include "client.hpp"
#include "mex.h"
#include "matlabclient.hpp"
#include "randexample.pb.h"


EXPORTED_FUNCTION mxArray *request(const char * const service, int version, 
                                   int m, int n)
{
  urpc::Client client("tcp://127.0.0.1:5555");
  randexample::Request request;
  randexample::Response response;
  
  request.set_m(m);
  request.set_n(n);
  client.sendRequest(service, version, request);
  client.getResponse(response);
  
  mxArray *mxResponse = mxCreateNumericMatrix(
    static_cast<mwSize>(m), static_cast<mwSize>(n), mxDOUBLE_CLASS, mxREAL);
  double *out = mxGetPr(mxResponse);
  for (int i = 0; i < response.r_size(); i++) {
    out[i] = response.r(i);
  }
  
  return mxResponse;
}

// Small demos of functionality

EXPORTED_FUNCTION mxArray *zeros(int m, int n)
{
  // rough replica of MATLAB zeros() function
  
  mxArray *zeroArray = mxCreateNumericMatrix(
    static_cast<mwSize>(m), static_cast<mwSize>(n), mxDOUBLE_CLASS, mxREAL);
  return zeroArray;
}
