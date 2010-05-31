# examples/cpp/CMakeLists.txt
#
# Build cpp examples

# command line client
file (GLOB cmdclientSource cmdclient.* randexample.*)
add_executable(cmdclient ${cmdclientSource})
add_dependencies(cmdclient client)
target_link_libraries (cmdclient client)

# MATLAB plugin client
file (GLOB matlabclientSource matlabclient.* randexample.*)
add_library (matlabclient SHARED ${matlabclientSource})
add_dependencies(matlabclient client)
target_link_libraries (matlabclient client libmx libmex libmat)