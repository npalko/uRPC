#include <iostream>
#include "pb/doubles.pb.h"
#include "glob.hpp"



int main (int argc, char **argv) {

  urpc::oglob glob("somefile.pbuf");
  urpc::test::pb::Array doubles;
  
  for (int i=0; i != 10; ++i) {
    for (int j=0; j != 131070; j++) {
      doubles.add_r (static_cast<double>(j));
    }
    glob.write (doubles);
    doubles.Clear();
  }
  
  return 0;
}