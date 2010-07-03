# src/kerberos/CMakeLists.txt
#
# Build multi-platform interface for Kerberos authentication

if (WIN32)
  set (kerb kerberos-win.cpp)
elseif (APPLE)
  set (kerb kerberos-osx.cpp)
else (WIN32) # BSD
  set (kerb kerberos.cpp)
endif (WIN32)

add_library (kerberos STATIC kerberos.hpp ${kerb})