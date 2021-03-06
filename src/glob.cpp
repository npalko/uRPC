// src/glob.cpp
//
//

#include <cassert>
#include <vector>
#include <boost/cstdint.hpp>
#include "exception.hpp"
#include "glob.hpp"

namespace urpc {

iglob::iglob (const std::string &filename) {
  using namespace std;
  
  file.exceptions (ifstream::failbit | ifstream::badbit);
  file.open (filename.c_str(), ios::binary | ios::in);
}
bool iglob::read (google::protobuf::Message &message) {
  uint32_t length;
  
  file.read (reinterpret_cast<char*>(&length), sizeof(length));
  if (file.eof()) {
    return false;
  }
  
  std::vector<char> buffer (length); 
  file.read (&buffer[0], length);
  bool parseSuccess = message.ParseFromArray (&buffer[0], length);
  
  if (!parseSuccess) {
    throw urpc::GlobError ("ParseFromArray failure");
  }
  
  return true;
}

oglob::oglob (const std::string &filename) {
  using namespace std;
  
  file.exceptions (ifstream::failbit | ifstream::badbit);
  file.open (filename.c_str(), ios::binary | ios::out | ios::trunc);
}
void oglob::write (const google::protobuf::Message &message) {
  uint32_t length = message.ByteSize ();

  //std::vector<char> line(3);
  //memcpy (&length, &line[0], 4);
  //file.write (line, 4);
  
  file.write (reinterpret_cast<char*>(&length), sizeof(length));
  bool serializeSuccess = message.SerializeToOstream (&file);
  
  if (!serializeSuccess) {
    throw urpc::GlobError ("SerializeToOstream failure");
  }
}


}
