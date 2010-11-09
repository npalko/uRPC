# test/CMakeLists.txt
#
# 

# DNS
add_executable (testdns testdns.cpp)
add_dependencies (testdns dns)
target_link_libraries (testdns ${EXTRA_LIBS})

# Protobuf Globbing
file (GLOB writeGlobSource writeglob.* pb/doubles.*)
add_executable (writeglob ${writeGlobSource})
add_dependencies (writeglob glob)
target_link_libraries (writeglob ${EXTRA_LIBS})

file (GLOB readGlobSource readglob.* pb/doubles.*)
add_executable (readglob ${readGlobSource})
add_dependencies (readglob glob)
target_link_libraries (readglob ${EXTRA_LIBS})

# Thread testing
file (GLOB threadSource threadtest.*)
add_library (threadTest STATIC ${threadSource})

add_executable (boosttest boosttest.cpp)
target_link_libraries (boosttest ${EXTRA_LIBS})

# multithread server w/client
#add_executable (client client.cpp)
#target_link_libraries (client ${EXTRA_LIBS})
#
#add_executable (server server.cpp)
#target_link_libraries (server ${EXTRA_LIBS})
