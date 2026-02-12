#include "adder.h"
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]) {
  int a, b;

  if (argc == 3) {
    std::stringstream ssa(argv[1]);
    std::stringstream ssb(argv[2]);
    ssa >> a;
    ssb >> b;
  } else {
    // If arguments are not provided, allow user to input them
    std::cin >> a >> b;
  }

  int c = add(a, b);
  std::cout << c << std::endl;

  return 0;
}
