// Demonstration of a single-threaded client

#include <cstdio>
#include "randexample/randexample.pb.h"
#include "client.hpp"

int main(int argc, char **argv) {
  if (argc != 3) {
    printf ("usage: %s <nMessage> <nSample>\n", "cmdclient");
    return 1;
  }
  int nMessage = atoi(argv[1]); 
  int nSample = atoi(argv[2]);

  urpc::Client client("tcp://127.0.0.1:5555");
  randexample::Request request;
  randexample::Reply reply;
  bool isMore;
  
  request.set_nmessage(nMessage);
  request.set_nsample(nSample);
  client.sendRequest("RandExampleRequest", 1, request);
  printf("[RandExampleRequest] (nMesage=%d,nSample=%d)\n", nMessage, nSample);


  do {
    isMore = client.getReply (reply);

    printf ("Reply block:\n");
    for (int i = 0; i < reply.r_size(); i++) {
      printf("%f\n", reply.r(i));
    }
    reply.Clear();
  } while (isMore);


  return 0;
}
