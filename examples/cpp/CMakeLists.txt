# examples/cpp/CMakeLists.txt
# 
# Build cpp examples

# command line client
file (GLOB cmdclientSource cmdclient.* randexample/randexample.*)
add_executable(cmdclient ${cmdclientSource})
add_dependencies(cmdclient client)
target_link_libraries (cmdclient client)

# MATLAB plugin client
if (BUILD_MATLAB)
  file (GLOB matlabclientSource matlabclient.* randexample/randexample.*)
  add_library (matlabclient SHARED ${matlabclientSource})
  add_dependencies(matlabclient client)
  target_link_libraries (matlabclient client libmx libmex libmat)
endif (BUILD_MATLAB)
