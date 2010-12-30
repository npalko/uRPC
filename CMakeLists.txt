# CMakeLists.txt
#
# Build uRPC

cmake_minimum_required (VERSION 2.8)
project (uRPC)

option (BUILD_MATLAB "Build the MATLAB C++ client plugin" OFF) 
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREADED ON)

find_package (Boost COMPONENTS system thread REQUIRED)
#find_package (Kerberos REQUIRED)
#find_package (LDAP REQUIRED)
find_package (Matlab)
#find_package (Pantheios REQUIRED)
find_package (Protobuf REQUIRED)
#find_package (STLSoft REQUIRED)
find_package (ZeroMQ REQUIRED)

if (WIN32)
  add_definitions (-D_WIN32_WINNT=0x0501)
endif ()

include_directories (
  ${Boost_INCLUDE_DIRS}
  ${Matlab_INCLUDE_DIR}
  ${Pantheios_INCLUDE_DIR}
  ${Protobuf_INCLUDE_DIR}
  ${STLSoft_INCLUDE_DIR}
  ${ZeroMQ_INCLUDE_DIR}
  src
)

add_subdirectory (src/dns)
add_subdirectory (src/kerberos)
add_subdirectory (src/ldap)
add_subdirectory (src)
add_subdirectory (examples/cpp)
add_subdirectory (test)
