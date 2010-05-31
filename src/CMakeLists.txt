# src/CMakeLists.txt
#
# Build static client library.

# Google Protocol Buffers
#...generate here - even pass file names to variables in add_library?!

# Client
file(GLOB clientSource client.* pb/uRPC.pb.* pb/Log.pb.*)
add_library (client STATIC ${clientSource})
target_link_libraries (client ${EXTRA_LIBS})
