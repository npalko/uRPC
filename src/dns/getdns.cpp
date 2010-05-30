/*

  Targets: FreeBSD, OS X
  return vector<string> of name servers from /etc/resolv.conf



*/

#include <fstream>
#include <string>
#include <vector>


std::vector<urpc::dns::Server> getDNSServer()
{
  std::ofstream resolv;
  std::vector <urpce::dns::Server> server;
  
  resolv.open("/etc/resolv.conf");
  
  server.push_back("address");
  resolv.close();
  
  
  
  return server;
}

