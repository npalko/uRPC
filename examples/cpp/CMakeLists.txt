# examples/cpp/CMakeLists.txt
# 
# 

# randexample command line client
file (GLOB cmdclientSource cmdclient.* randexample/randexample.*)
add_executable (cmdclient ${cmdclientSource})
target_link_libraries (cmdclient client)

# randexample multithreaded server
file (GLOB randServerSource randserver.cpp randexample/randexample.*)
add_executable (randServer ${randServerSource})
target_link_libraries (randServer server)

# randexample MATLAB plugin client
if (BUILD_MATLAB)
  file (GLOB matlabclientSource matlabclient.* randexample/randexample.*)
  add_library (matlabclient SHARED ${matlabclientSource})
  target_link_libraries (matlabclient 
  	client 
		${Matlab_MX_LIBRARY}
		${Matlab_MEX_LIBRARY}
		${Matlab_MAT_LIBRARY}
  )
endif ()

