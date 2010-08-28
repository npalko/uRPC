// src/glob/glob.hpp
//
//

#ifndef URPC_GLOB_HPP
#define URPC_GLOB_HPP

#include <fstream>
#include <google/protobuf/message.h>

namespace urpc {


class glob {
  public:
    glob ();
  protected:
    std::fstream file;
    static const int IntSize = 4;
};

class iglob : private glob {
  public:
    iglob (const std::string &);
    bool read (google::protobuf::Message &);
};

class oglob : private glob {
  public:
    oglob (const std::string &);
    void write (const google::protobuf::Message &);
};


}
#endif // URPC_GLOB_HPP
