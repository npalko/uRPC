// src/glob/glob.hpp
//
//

#ifndef URPC_GLOB_HPP
#define URPC_GLOB_HPP

#include <fstream>
#include <google/protobuf/message.h>

namespace urpc {

class iglob {
  public:
    /** Open a glob file for reading
      * \param filename file to open for reading
      */ 
    iglob (const std::string &);

    /** Read a protobuf from the file
      * \param message destination of data 
      * \return TRUE if additional messages are available
      */
    bool read (google::protobuf::Message &);
  private:
    std::fstream file;
};

class oglob {
  public:
    /** Open a file for writing
      * \param filename file to write
      */ 
    oglob (const std::string &);

    /** Write a protobuf from the file
      * \param message data to write
      */
    void write (const google::protobuf::Message &);
  private:
    std::fstream file;
};


}
#endif // URPC_GLOB_HPP
