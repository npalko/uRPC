# command line options
#   -D CMAKE_MODULE_PATH ../cmake-modules
# 

cmake_minimum_required (VERSION 2.8)
project (uRPC)

# depreciate the following:
set (CMAKE_MODULE_PATH ../../cmake-modules)
set (PROTOBUF_INCLUDE_DIR ../../protobuf/src)
set (PROTOBUF_LIBRARY "C:/Users/Nicholas Palko/Documents/Development/protobuf/vsprojects/Release")
# end depr.

find_package (ProtocolBuffers)
#find_package (ZeroMQ)

add_subdirectory (src)
