#include <iostream>
#include "pb/doubles.pb.h"
#include "glob.hpp"



int main (int argc, char **argv) {

  urpc::oglob glob("somefile.pbuf");
  urpc::test::pb::Array doubles;
  
  int j0 = 0;
  int j;
  for (int i=0; i != 4; ++i) {
    for (j=j0; j != j0+10; j++) {
      doubles.add_r (static_cast<double>(j));
    }
    j0 = j;
    glob.write (doubles);
    doubles.Clear();
  }
  
  return 0;
}