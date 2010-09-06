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
#include <boost/shared_ptr.hpp>

#include "dns/dns.hpp"
#include "exception.hpp"


namespace urpc {
namespace dns {

std::vector<boost::asio::ip::address> getServer() {
  FIXED_INFO *pFixedInfo;
  ULONG ulOutBufLen;
  DWORD dwRetVal;
  IP_ADDR_STRING *pIPAddr;
  std::vector<boost::asio::ip::address> server;
  
  //boost::shared_ptr<FIXED_INFO> pFixedInfo (new(sizeof(FIXED_INFO));
  pFixedInfo = (FIXED_INFO *) malloc (sizeof(FIXED_INFO));
  ulOutBufLen = sizeof (FIXED_INFO);
  
  // get the size of pFixedInfo
  GetNetworkParams (pFixedInfo, &ulOutBufLen);
  free (pFixedInfo);
  
  // get actual data
  pFixedInfo = (FIXED_INFO *) malloc (ulOutBufLen);
  dwRetVal = GetNetworkParams (pFixedInfo, &ulOutBufLen);
  if (dwRetVal == NO_ERROR) {
    
    server.push_back (boost::asio::ip::address::from_string (
      pFixedInfo->DnsServerList.IpAddress.String));

    pIPAddr = pFixedInfo->DnsServerList.Next;
    while (pIPAddr) {
      server.push_back (boost::asio::ip::address::from_string (
        pIPAddr->IpAddress.String));
      pIPAddr = pIPAddr->Next;
    }
  } else {
     printf("GetNetworkParams failed with error: %d\n", dwRetVal);
  }

  free (pFixedInfo);
  
  return server;
}


}
}
