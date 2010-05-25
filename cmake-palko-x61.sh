#!/bin/bash
protoc --cpp_out=src --proto_path=protobuf protobuf/*.proto
protoc --python_out=python/urpc --proto_path=protobuf protobuf/*.proto
cd build && cmake .. \
  -DCMAKE_MODULE_PATH="C:/Users/Nicholas Palko/Documents/Development/cmake-modules" \
  -DZMQ_INCLUDE_DIR="C:/Users/Nicholas Palko/Documents/Development/zeromq2/include" \
  -DZMQ_LIBRARY="C:/Users/Nicholas Palko/Documents/Development/zeromq2/lib" \
  -DPROTOBUF_INCLUDE_DIR="C:/Users/Nicholas Palko/Documents/Development/protobuf/src" \
  -DPROTOBUF_LIBRARY="C:/Users/Nicholas Palko/Documents/Development/protobuf/vsprojects/Release" \
  -DMATLAB_INCLUDE_DIR="C:/Program Files/MATLAB/R2009a/extern/include" \
  -DMATLAB_LIBRARY="C:/Program Files/MATLAB/R2009a/extern/lib/win32/microsoft"