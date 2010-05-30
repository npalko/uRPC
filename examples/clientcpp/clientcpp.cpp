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

  printf("[RandExampleRequest] (m=%d,n=%d)\n", m, n);
  
  randexample::Request randRequst;
  randexample::Response randResponse;
  urpc::Client client;

  randRequst.set_m(m);
  randRequst.set_n(n);

  client.connect();
  client.sendRequest("RandExampleRequest", 1, randRequst);
    
  bool isEmpty = false;
  while (!isEmpty) {
    isEmpty = client.getResponse(randResponse);
    for (int i = 0; i < randResponse.r_size(); i++) {
      std::cout << randResponse.r(i) << std::endl;
    }
  }
  
  return 0;
}
