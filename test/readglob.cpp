#include <iostream>
#include "pb/doubles.pb.h"
#include "glob.hpp"



int main (int argc, char **argv) {
  
  urpc::Glob glob("somefile.pbuf", urpc::Read);
  urpc::test::pb::Array doubles;
  
  while (glob.read (doubles)) {
    for (int i=0; i != doubles.r_size(); ++i) {
      std::cout << doubles.r(i) << std::endl;
    }
    doubles.Clear();
  }

  return 0;
}