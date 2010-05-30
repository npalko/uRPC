# CMakeLists.txt
#
# Build uRPC

cmake_minimum_required (VERSION 2.8)
project (uRPC)

set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREADED ON)
find_package (Boost REQUIRED) #memory
#find_package (Kerberos REQUIRED)
#find_package (Matlab)
#find_package (ProtocolBuffers REQUIRED)
#find_package (ZeroMQ REQUIRED)

#TARGET_LINK_LIBRARIES(wakeup RELEASE ${wakeup_SRCS})
#TARGET_LINK_LIBRARIES(wakeupd DEBUG ${wakeup_SRCS})


# EXTERNAL 
# Boost
include_directories(${Boost_INCLUDE_DIRS})

# Google Protobuf
include_directories (${PROTOBUF_INCLUDE_DIR})
link_directories (${PROTOBUF_LIBRARY})
add_library (libprotobuf${CMAKE_STATIC_LIBRARY_SUFFIX} STATIC IMPORTED)
set (EXTRA_LIBS ${EXTRA_LIBS} libprotobuf)

# ZeroMQ
include_directories (${ZMQ_INCLUDE_DIR})
link_directories (${ZMQ_LIBRARY})
add_library (libzmq${CMAKE_SHARED_LIBRARY_SUFFIX} SHARED IMPORTED)
set (EXTRA_LIBS ${EXTRA_LIBS} libzmq)

# Matlab
#include_directories (${MATLAB_INCLUDE_DIR})
#link_directories (${MATLAB_LIBRARY})


# INTERNAL 


# DNS 
include_directories (${PROJECT_SOURCE_DIR}/src/dns)
add_subdirectory (src/dns)
set (EXTRA_LIBS ${EXTRA_LIBS} dns)
if (WIN32)
  set (EXTRA_LIBS ${EXTRA_LIBS} IPHLPAPI)
endif (WIN32)

# Kerberos
include_directories (${PROJECT_SOURCE_DIR}/src/kerberos)
add_subdirectory (src/kerberos)
#set (EXTRA_LIBS ${EXTRA_LIBS} kerberos)


include_directories (src)
add_subdirectory (src)

# EXAMPLES
add_subdirectory (examples/cpp)
