// src/glob.cpp
//
//

#include <cassert>
#include <cstdio>
#include <vector>
#include "glob.hpp"

namespace urpc {

glob::glob() {

  assert (sizeof(int) == IntSize);
}

iglob::iglob (const std::string &filename) {

  using namespace std;
  stream.open (filename.c_str(), ios::binary | ios::in);
}
bool iglob::read (google::protobuf::Message &message) {
  // assumes we are ready for the next block of data
  // if read completed

  bool parseSuccess;
  int length;
  
  stream.read (reinterpret_cast<char*>(&length), IntSize);
  if (stream.eof()) {
    return false;
  }

  printf ("Glob::read length=%d\n", length);
  std::vector<char> buffer (length);
  stream.read (&buffer[0], length);
  if (stream.gcount() != length) {
    throw urpc::GlobError ("Could not read bytes specified by offset");
  }

  parseSuccess = message.ParseFromArray (&buffer[0], length);
  if (!parseSuccess) {
    throw urpc::GlobError ("ParseFromArray failure");
  }

  return true;
}

oglob::oglob (const std::string &filename) {

  using namespace std;
  stream.open (filename.c_str(), ios::binary | ios::out | ios::trunc);
}
void oglob::write (const google::protobuf::Message &message) {

  bool serializeSuccess;
  int length;

  length = message.ByteSize ();
  stream.write (reinterpret_cast<char*>(&length), IntSize);
  serializeSuccess = message.SerializeToOstream (&stream);

  if (!serializeSuccess) {
    throw urpc::GlobError ("SerializeToOstream failure");
  }
}


}
