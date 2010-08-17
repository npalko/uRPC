#include <iostream>
#include "pb/doubles.pb.h"
#include "glob.hpp"



int main (int argc, char **argv) {

  urpc::Glob glob("somefile.pbuf", urpc::Write);
  int j0 = 0;
  int j;

  for (int i=0; i != 4; ++i) {
    
    urpc::test::pb::Array doubles;
    for (j=j0; j != j0+10; j++) {
      doubles.add_r (static_cast<double>(j));
    }
    j0 = j;
    glob.write (doubles);
  }
  
  return 0;
}