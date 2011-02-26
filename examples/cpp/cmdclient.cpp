// Demonstration of a single-threaded client

#include <cstdio>
#include <boost/lexical_cast.hpp>
#include "randexample/randexample.pb.h"
#include "client.hpp"

int main(int argc, char **argv) {
  if (argc != 3) {
    printf ("usage: %s <nMessage> <nSample>\n", "cmdclient");
    return 1;
  }
  int nMessage = boost::lexical_cast<int>(argv[1]);
  int nSample  = boost::lexical_cast<int>(argv[2]);
  
  urpc::Client client ("tcp://127.0.0.1:5555");
  randexample::Request request;
  randexample::Reply reply;
  
  request.set_nmessage (nMessage);
  request.set_nsample (nSample);
  client.sendRequest("Rand", 1, request);
  printf("[Rand] (nMesage=%d,nSample=%d)\n", nMessage, nSample);
  
  bool thereIsMore;
  do {
    thereIsMore = client.getReply (reply);
    
    printf ("Reply block:\n");
    for (int i = 0; i < reply.r_size(); i++) {
      printf("%f\n", reply.r(i));
    }
    reply.Clear();
  } while (thereIsMore);

  return 0;
}
