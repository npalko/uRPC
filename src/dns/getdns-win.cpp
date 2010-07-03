// src/dns/getdns-win.cpp
//
//
// http://msdn.microsoft.com/en-us/library/aa365968(VS.85).aspx
// Link with IPHlpAPI.lib

#include <winsock2.h>
#include <iphlpapi.h>
#include <stdlib.h>
#include <windows.h>

#include <cstdio>
#include <string>
#include <vector>
#include <boost/asio.hpp>

#include "dns/dns.hpp"


namespace urpc {
namespace dns {

void getAddress(std::vector<boost::asio::ip::address> &server) {
  FIXED_INFO *pFixedInfo;
  ULONG ulOutBufLen;
  IP_ADDR_STRING *pIPAddr;
  
  pFixedInfo = (FIXED_INFO *) malloc (sizeof(FIXED_INFO));
  ulOutBufLen = sizeof (FIXED_INFO);
  
  // get the size of pFixedInfo
  GetNetworkParams (pFixedInfo, &ulOutBufLen);
  free (pFixedInfo);
  
  // get actual data
  pFixedInfo = (FIXED_INFO *) malloc (ulOutBufLen);
  GetNetworkParams (pFixedInfo, &ulOutBufLen);
  
  do {
    server.push_back (boost::asio::ip::address::from_string (
      pFixedInfo->DnsServerList.IpAddress.String));  
    pIPAddr = pFixedInfo->DnsServerList.Next;
  } while (pIPAddr);

  free (pFixedInfo);
}


}
}
