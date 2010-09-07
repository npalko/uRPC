// src/glob.cpp
//
//

#include <cassert>
#include <vector>
#include "exception.hpp"
#include "glob.hpp"

namespace urpc {

glob::glob() {
  using namespace std;
  file.exceptions (ifstream::failbit | ifstream::badbit);
}

iglob::iglob (const std::string &filename) {

  using namespace std;
  file.open (filename.c_str(), ios::binary | ios::in);
}
bool iglob::read (google::protobuf::Message &message) {

  bool parseSuccess;
  __int32 length;
  
  file.read (reinterpret_cast<char*>(&length), sizeof(length));
  if (file.eof()) {
    return false;
  }

  std::vector<char> buffer (length);
  file.read (&buffer[0], length);
  parseSuccess = message.ParseFromArray (&buffer[0], length);
  
  if (!parseSuccess) {
    throw urpc::GlobError ("ParseFromArray failure");
  }

  return true;
}

oglob::oglob (const std::string &filename) {

  using namespace std;
  file.open (filename.c_str(), ios::binary | ios::out | ios::trunc);
}
void oglob::write (const google::protobuf::Message &message) {

  bool serializeSuccess;
  __int32 length;

  length = message.ByteSize ();
  file.write (reinterpret_cast<char*>(&length), sizeof(length));
  serializeSuccess = message.SerializeToOstream (&file);

  if (!serializeSuccess) {
    throw urpc::GlobError ("SerializeToOstream failure");
  }
}


}
