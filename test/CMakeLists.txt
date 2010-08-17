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
