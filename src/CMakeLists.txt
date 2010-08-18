# src/CMakeLists.txt
#
# Build static client library.

# Google Protocol Buffers
#...generate here - even pass file names to variables in add_library?!

# Client
file (GLOB clientSource client.* exception.* pb/uRPC.pb.* pb/Log.pb.*)
add_library (client STATIC ${clientSource})
add_dependencies (client dns kerberos)
target_link_libraries (client ${EXTRA_LIBS})

