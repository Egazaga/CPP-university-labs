#include <iostream>

#include "prog1.hpp"
#include "prog2.hpp"

int main(int argc, char *argv[])
{
  try {
    //freopen("data", "r", stdin);                //debug tools
    if (argc != 2) {
      throw std::invalid_argument("Wrong number of arguments");
    } else if (std::stoi(argv[1]) == 1) {
      prog1();
    } else if (std::stoi(argv[1]) == 2) {
      prog2();
    } else {
      throw std::invalid_argument("Wrong arguments");
    }
  }
  catch (std::exception &oof) {
    std::cout << oof.what();
    return 1;
  }
  return 0;
}
