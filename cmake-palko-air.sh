#!/bin/bash
protoc --cpp_out=src/pb --python_out=python/urpc --proto_path=protobuf protobuf/*.proto
protoc --cpp_out=examples/cpp/randexample --python_out=examples/python --proto_path=examples/protobuf examples/protobuf/*.proto
protoc --cpp_out=test/pb --proto_path=test/protobuf test/protobuf/*.proto
cd build && cmake .. \
  -DCMAKE_MODULE_PATH="/Users/npalko/Development/cmake-modules" \
  -DBOOST_ROOT="/Users/npalko/Development/boost_1_45_0" \
  -DZMQ_INCLUDE_DIR="/Users/npalko/Development/zeromq2/include" \
  -DZMQ_LIBRARY=/usr/local/lib \
  -DPROTOBUF_INCLUDE_DIR="/Users/npalko/Development/protobuf/src" \
  -DPROTOBUF_LIBRARY=/usr/local/lib \
  -DMATLAB_INCLUDE_DIR="/Applications/MATLAB_R2009b.app/extern/include" \
  -DMATLAB_LIBRARY="/Applications/MATLAB_R2009b.app/extern/lib/maci64"

