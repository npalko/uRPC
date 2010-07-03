# src/dns/CMakeLists.txt
#
#

if (WIN32)
  set (getdns getdns-win.cpp)
elseif (APPLE)
  set (getdns getdns-osx.cpp)
else (WIN32) # BSD
  set (getdns getdns.cpp)
endif (WIN32)

add_library (dns STATIC dns.cpp dns.hpp ${getdns})
