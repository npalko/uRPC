function matlabrequestdemo()

  cd('C:\Users\Nicholas Palko\Documents\Development\uRPC\examples\cpp');
  addpath('C:\Users\Nicholas Palko\Documents\Development\uRPC\build\examples\cpp\Release');
  loadlibrary('matlabclient', 'matlabclient.hpp');
  libfunctions('matlabclient')
  
  tic(); calllib('matlabclient','request', 'someapifunction', 1, 1, 131071); toc();
  
  calllib('matlabclient','request', 'someapifunction', 8, 30, 4);
  unloadlibrary('matlabclient')
  
  
end