
add_executable (testdns testdns.cpp)
add_dependencies (testdns dns)
target_link_libraries (testdns ${EXTRA_LIBS})
