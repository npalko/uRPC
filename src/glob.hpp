// src/glob/glob.hpp
//
//

/*
  protobufs should not exceed 1MB in size
  to create larger messages (for writting to file or sending larger packets
  than 1MB through ZMQ) we glob in the following format:
  
  [int32, number of bytes of protobuf following this marker]
  [protobuf, less than 1MB]
  [int32, next marker]
  
  if EOF is reached, the stream is complete. We use little-endian 
  write format to match with protobufs.
*/


#ifndef URPC_GLOB_HPP
#define URPC_GLOB_HPP

#include <fstream>
#include <google/protobuf/message.h>
#include "exception.hpp"


namespace urpc {

enum GlobIO {Read, Write};

class Glob {
  public:
    Glob (const std::string &, GlobIO);
    bool read (google::protobuf::Message &);
    void write (const google::protobuf::Message &);
  private:
    std::fstream stream;
    static const int IntSize = 4;
};


}
#endif // URPC_GLOB_HPP