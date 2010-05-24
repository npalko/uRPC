# Google Protocol Buffers

protoc (cpp file1.proto file2.proto)
include_directories (${PROTOBUF_INCLUDE_DIR})
link_directories (${PROTOBUF_LIBRARY})
add_library (libprotobuf${CMAKE_STATIC_LIBRARY_SUFFIX} STATIC IMPORTED)

# ZeroMQ

include_directories (${ZMQ_INCLUDE_DIR})
link_directories (${ZMQ_LIBRARY})
add_library (libzmq${CMAKE_SHARED_LIBRARY_SUFFIX} SHARED IMPORTED)

# Executable

add_executable (uRPC juststart.cpp uRPC.pb.cc Log.pb.cc)
target_link_libraries (uRPC libprotobuf libzmq)

# MATLAB shared library

include_directories (${MATLAB_INCLUDE_DIR})
link_directories (${MATLAB_LIBRARY})
add_library(matlab SHARED matlab.cpp uRPC.pb.cc Log.pb.cc)
target_link_libraries (matlab libmx libmex libmat libprotobuf libzmq)

#TARGET_LINK_LIBRARIES(wakeup RELEASE ${wakeup_SRCS})
#TARGET_LINK_LIBRARIES(wakeupd DEBUG ${wakeup_SRCS})