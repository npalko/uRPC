#!/bin/bash
protoc --cpp_out=src/pb --python_out=python/urpc --proto_path=protobuf protobuf/*.proto
protoc --cpp_out=examples/cpp --python_out=examples/python --proto_path=examples/protobuf examples/protobuf/*.proto
cd build && cmake .. \
  -DCMAKE_MODULE_PATH="C:/Users/Nicholas Palko/Documents/Development/cmake-modules" \
  -DBOOST_ROOT="C:/Users/Nicholas Palko/Documents/Development/boost" \
  -DZMQ_INCLUDE_DIR="C:/Users/Nicholas Palko/Documents/Development/zeromq2/include" \
  -DZMQ_LIBRARY="C:/Users/Nicholas Palko/Documents/Development/zeromq2/lib" \
  -DPROTOBUF_INCLUDE_DIR="C:/Users/Nicholas Palko/Documents/Development/protobuf/src" \
  -DPROTOBUF_LIBRARY="C:/Users/Nicholas Palko/Documents/Development/protobuf/vsprojects/Release" \
  -DMATLAB_INCLUDE_DIR="C:/Program Files/MATLAB/R2009a/extern/include" \
  -DMATLAB_LIBRARY="C:/Program Files/MATLAB/R2009a/extern/lib/win32/microsoft"