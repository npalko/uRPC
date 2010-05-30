# examples/clientcpp/CMakeLists.txt
#
# Build clientcpp example.

file (GLOB clientcppSource clientcpp.* randexample.*)
add_executable(clientcpp ${clientcppSource})
add_dependencies(clientcpp client)
target_link_libraries (clientcpp client)