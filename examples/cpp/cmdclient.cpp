// Demonstration of a single-threaded client

#include <cstdio>

#include "randexample.pb.h"
#include "client.hpp"

int main(int argc, char **argv) {
  if (argc != 3) {
    printf ("usage: %s <num_rows> <num_columns>\n", "clientcpp");
    return 1;
  }
  int m = atoi(argv[1]); 
  int n = atoi(argv[2]);

  urpc::Client client;
  randexample::Request requst;
  randexample::Response response;
  
  requst.set_m(m);
  requst.set_n(n);
  client.sendRequest("RandExampleRequest", 1, requst);
  printf("[RandExampleRequest] (m=%d,n=%d)\n", m, n);

  client.getResponse(response);
  for (int i = 0; i < response.r_size(); i++) {
    printf("%f\n", response.r(i));
  }

  return 0;
}
