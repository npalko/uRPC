// src/glob.cpp
//
//

#include <cassert>
#include <cstdio>
#include "glob.hpp"

namespace urpc {

Glob::Glob (const std::string &filename, urpc::GlobIO direction) {

  using namespace std;
  assert (sizeof(int) == IntSize);

  switch (direction) {
    case urpc::Read:
      stream.open (filename.c_str(), ios::binary | ios::in);
      break;
    case urpc::Write:
      stream.open (filename.c_str(), ios::binary | ios::out | ios::trunc);
      break;
  }
}

bool Glob::read (google::protobuf::Message &message) {

  // assumes we are ready for the next block of data
  // if read completed

  bool parseSuccess;
  int length;
  char *data;
  
  stream.read (reinterpret_cast<char*>(&length), IntSize);
  if (stream.eof()) {
    return false;
  }

  printf ("Glob::read length=%d\n", length);
  data = new char[length];
  stream.read (data, length);
  parseSuccess = message.ParseFromArray (data, length);
  delete [] data;

  if (!parseSuccess) {
    throw urpc::GlobError ("ParseFromArray failure");
  }

  return true;
}

void Glob::write (const google::protobuf::Message &message) {

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
