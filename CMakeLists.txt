# necissary command line options
#   -D CMAKE_MODULE_PATH ../cmake-modules
# how to build:
#   cd uRPC/build
#   cmake ..

cmake_minimum_required (VERSION 2.8)
project (uRPC)

# depreciate the following:
set (CMAKE_MODULE_PATH "C:/Users/Nicholas Palko/Documents/Development/cmake-modules")
set (PROTOBUF_INCLUDE_DIR "C:/Users/Nicholas Palko/Documents/Development/protobuf/src")
set (PROTOBUF_LIBRARY "C:/Users/Nicholas Palko/Documents/Development/protobuf/vsprojects/Release")
set (ZMQ_INCLUDE_DIR "C:/Users/Nicholas Palko/Documents/Development/zeromq2/include")
set (ZMQ_LIBRARY "C:/Users/Nicholas Palko/Documents/Development/zeromq2/lib")
# end depr.

find_package (ProtocolBuffers REQUIRED)
#find_package (ZeroMQ REQUIRED)

add_subdirectory (src)
