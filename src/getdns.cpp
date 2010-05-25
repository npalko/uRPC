/*

  Targets: FreeBSD, OS X
  return vector<string> of name servers from /etc/resolv.conf



*/

#include <fstream>
#include <string>
#include <vector>


std::vector<std::string> getdns()
{
  std::ofstream resolv;
  std::vector <std::string> server;
  
  resolv.open("/etc/resolv.conf");
  
  server.push_back("address");
  resolv.close();
  
  
  
  return server;
}

