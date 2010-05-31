function matlabrequestdemo()

  cd('C:\Users\Nicholas Palko\Documents\Development\uRPC\examples\cpp');
  addpath('C:\Users\Nicholas Palko\Documents\Development\uRPC\build\examples\cpp\Release');
  loadlibrary('matlabclient', 'matlabclient.hpp');
  libfunctions('matlabclient')
  
  
  calllib('matlabclient','request', 'someapifunction', 8, 30, 4);
  unloadlibrary('matlabclient')
  
  
end