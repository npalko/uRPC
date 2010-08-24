#include <iostream>
#include "pb/doubles.pb.h"
#include "glob.hpp"



int main (int argc, char **argv) {
  
  urpc::iglob glob("somefile.pbuf");
  urpc::test::pb::Array doubles;
  double total;
  
  while (glob.read (doubles)) {
    total = 0;
    for (int i=0; i != doubles.r_size(); ++i) {
      total += doubles.r(i);
    }
    std::cout << total << std::endl;
    doubles.Clear();
  }

  return 0;
}