
include_directories (${MATLAB_INCLUDE_DIR})
link_directories (${MATLAB_LIBRARY})
add_library(matlab SHARED matlab.cpp)
target_link_libraries (matlab libmx libmex libmat)


protoc (cpp file1.proto file2.proto)

include_directories (${PROTOBUF_INCLUDE_DIR})
link_directories (${PROTOBUF_LIBRARY})
add_library (libprotobuf.lib STATIC IMPORTED)

include_directories (${ZMQ_INCLUDE_DIR})
link_directories (${ZMQ_LIBRARY})
add_library (libzmq.dll SHARED IMPORTED)

add_executable (uRPC juststart.cpp uRPC.pb.cc Log.pb.cc)
target_link_libraries (uRPC libprotobuf libzmq)

#TARGET_LINK_LIBRARIES(wakeup RELEASE ${wakeup_SRCS})
#TARGET_LINK_LIBRARIES(wakeupd DEBUG ${wakeup_SRCS})