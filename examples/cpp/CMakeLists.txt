# examples/cpp/CMakeLists.txt
# 
# Build cpp examples

# randexample command line client
file (GLOB cmdclientSource cmdclient.* randexample/randexample.*)
add_executable(cmdclient ${cmdclientSource})
add_dependencies(cmdclient client)
target_link_libraries (cmdclient client)

# randexample multithreaded server
file (GLOB randServerSource randserver.cpp randexample/randexample.*)
add_executable(randServer ${randServerSource})
add_dependencies(randServer server)
target_link_libraries(randServer server)

# randexample MATLAB plugin client
if (BUILD_MATLAB)
  file (GLOB matlabclientSource matlabclient.* randexample/randexample.*)
  add_library (matlabclient SHARED ${matlabclientSource})
  add_dependencies(matlabclient client)
  target_link_libraries (matlabclient client mx mex mat)
endif (BUILD_MATLAB)

