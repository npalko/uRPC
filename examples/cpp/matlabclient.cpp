// examples/cpp/matlabclient.cpp
//
//

#include "randexample.pb.h"
#include "client.hpp"

#include "mex.h"
#include "matlabclient.hpp"


EXPORTED_FUNCTION mxArray *request(const char *service, int version, 
  const mxArray *message)
{
  urpc::Client client;
  randexample::Request requst;
  randexample::Response response;
  
  requst.set_m(m);
  requst.set_n(n);
  
  client.sendRequest(service, version, requst);
  
  client.getResponse(response);
  for (int i = 0; i < response.r_size(); i++) {
    response.r(i);
  }

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
