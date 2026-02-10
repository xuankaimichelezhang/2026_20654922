#include "adder.h"
#include <iostream>
#include <sstream>


int main(int argc, char *argv[]) {
  int a, b, c;

  if (argc != 3) {
    a = 10;
    b = 20;
  } else {
    std::string sa(argv[1]);
    std::string sb(argv[2]);

    std::stringstream ssa(sa);
    std::stringstream ssb(sb);

    ssa >> a;
    ssb >> b;
  }

  c = add(a, b);
  std::cout << c;

  return 0;
}
