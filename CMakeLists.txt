# CMakeLists.txt
#
# Build uRPC

cmake_minimum_required (VERSION 2.8)
project (uRPC)

option (BUILD_MATLAB "Build the MATLAB C++ client plugin" ON) 

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
if (WIN32)
  add_definitions (-D_WIN32_WINNT=0x0501)
endif (WIN32)
include_directories (${Boost_INCLUDE_DIRS})
link_directories (${Boost_LIBRARY_DIRS})

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
if (BUILD_MATLAB)
  include_directories (${MATLAB_INCLUDE_DIR})
  link_directories (${MATLAB_LIBRARY})
endif (BUILD_MATLAB)


# INTERNAL 
include_directories (src)

# DNS 
add_subdirectory (src/dns)
set (EXTRA_LIBS ${EXTRA_LIBS} dns)
if (WIN32)
  set (EXTRA_LIBS ${EXTRA_LIBS} IPHlpAPI)
endif (WIN32)

# Kerberos
add_subdirectory (src/kerberos)
set (EXTRA_LIBS ${EXTRA_LIBS} kerberos)

# LDAP
add_subdirectory (src/ldap)
set (EXTRA_LIBS ${EXTRA_LIBS} ldap)

# Glob
add_library (glob STATIC src/glob.cpp src/glob.hpp)
set (EXTRA_LIBS ${EXTRA_LIBS} glob)

# must be added last, even though we specify depenceny. odd
add_subdirectory (src)

# EXAMPLES
add_subdirectory (examples/cpp)

# TESTING
add_subdirectory (test)
