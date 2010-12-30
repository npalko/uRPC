# src/CMakeLists.txt
#
# Glob, Client, Server

# Google Protocol Buffers
#...generate here - even pass file names to variables in add_library?!

# should be a function that returns files generated so file names are
# specified once here and used below
# add_custom_command (
#  OUTPUT uRPC.pb.cc uRPC.pb.h
#  COMMAND protoc --cpp out
#  COMMENT "generated É"
#)


# Glob
file (GLOB globSource glob.*)
add_library (glob STATIC ${globSource})
target_link_libraries (glob
  ${Protobuf_LIBRARY}
)

# Client
file (GLOB clientSource client.* exception.* pb/uRPC.pb.* pb/Log.pb.*)
add_library (client STATIC ${clientSource})
target_link_libraries (client
  dns
  kerberos
  ${Boost_SYSTEM_LIBRARY}
  ${Protobuf_LIBRARY}
  ${ZeroMQ_LIBRARY}
)

# Server
file (GLOB serverSource server.* exception.* pb/uRPC.pb.* pb/Log.pb.*)
add_library (server STATIC ${serverSource})
target_link_libraries (server 
  dns
  kerberos
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_THREAD_LIBRARY}
  ${Protobuf_LIBRARY}
  ${ZeroMQ_LIBRARY}
)
