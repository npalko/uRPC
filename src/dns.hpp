/*

Specification:

_Service._Proto.Name TTL Class SRV Priority Weight Port Target
_sip._tcp.example.com. 86400 IN SRV 0 5 5060 sipserver.example.com.

Verification:

Unix:     dig SRV _sip._tcp.example.com
Windows:  nslookup -type=srv _sip._tcp.example.com







*/


std::vector<std::string> getDNS();
std::vector<std::string> getSRV();
