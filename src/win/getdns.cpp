// http://msdn.microsoft.com/en-us/library/aa365968(VS.85).aspx

// Targets: Windows
// return vector<string> of name servers from /etc/resolv.conf

//
// Link with IPHlpAPI.lib
//
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "IPHLPAPI.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

int __cdecl main()
{

  FIXED_INFO *pFixedInfo;
  ULONG ulOutBufLen;
  DWORD dwRetVal;
  IP_ADDR_STRING *pIPAddr;

  pFixedInfo = (FIXED_INFO *) MALLOC(sizeof (FIXED_INFO));
  ulOutBufLen = sizeof (FIXED_INFO);

  GetNetworkParams(pFixedInfo, &ulOutBufLen);

  printf("DNS Servers:\n");
  printf("\t%s\n", pFixedInfo->DnsServerList.IpAddress.String);

  pIPAddr = pFixedInfo->DnsServerList.Next;
  while (pIPAddr) {
    printf("\t%s\n", pIPAddr->IpAddress.String);
    pIPAddr = pIPAddr->Next;
  }

  FREE(pFixedInfo);
  return 0;
}