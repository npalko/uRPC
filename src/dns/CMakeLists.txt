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

# change to linking to dns here
if (WIN32)
  set (EXTRA_LIBS ${EXTRA_LIBS} IPHlpAPI)
endif (WIN32)

add_library (dns STATIC dns.cpp dns.hpp ${getdns})
