# test/CMakeLists.txt
#
# 

# DNS
add_executable (testdns testdns.cpp)
add_dependencies (testdns dns)
target_link_libraries (testdns dns ${Boost_SYSTEM_LIBRARY})

# Protobuf Globbing
file (GLOB writeGlobSource writeglob.* pb/doubles.*)
add_executable (writeglob ${writeGlobSource})
target_link_libraries (writeglob glob ${Protobuf_LIBRARY})

file (GLOB readGlobSource readglob.* pb/doubles.*)
add_executable (readglob ${readGlobSource})
target_link_libraries (readglob glob ${Protobuf_LIBRARY})


