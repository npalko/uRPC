// Demonstration of a single-threaded client

#include <cstdio>

#include "randexample.pb.h"
#include "client.hpp"

int main(int argc, char **argv) {
  if (argc != 3) {
    printf ("usage: %s <num_rows> <num_columns>\n", "cmdclient");
    return 1;
  }
  int m = atoi(argv[1]); 
  int n = atoi(argv[2]);

  urpc::Client client("tcp://127.0.0.1:5555");
  randexample::Request request;
  randexample::Response response;
  
  request.set_m(m);
  request.set_n(n);
  client.sendRequest("RandExampleRequest", 1, request);
  printf("[RandExampleRequest] (m=%d,n=%d)\n", m, n);

  client.getResponse(response);
  for (int i = 0; i < response.r_size(); i++) {
    printf("%f\n", response.r(i));
  }

  return 0;
}
