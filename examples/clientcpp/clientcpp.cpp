// Demonstration of a single-threaded client

#include <cstdio>

#include "randexample.pb.h"
#include "client.hpp"

namespace clientcpp 
{
  int main(int argc, char **argv)
  {
    if (argc != 2) 
    {
      printf ("usage: clientcpp <num_rows> <num_columns>\n");
      return 1;
    }
    int m = atoi (argv[1]); 
    int n = atoi (argv[2]);
    
    randexample::Request randRequst;
    randexmaple::Response randResponse;
    urpc::Client client;
    
    client.connect();
    randRequst.set_m(m);
    randRequst.set_n(n);
    client.sendRequest("RandExampleRequest", 1, &randRequst);
    printf("[RandExampleRequest] (m=%d,n=%d)\n", m, n);
    
    bool isEmpty = false;
    while (!isEmpty)
    {
      isEmpty = client.getResponse(&randResponse);
      // print to screen or file or something
      // std::count << randResponse.message() << std::endl;
    }
    
    return 0;
  }
}