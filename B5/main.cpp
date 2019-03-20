#include <iostream>
#include <string>

#include "algorithm.hpp"

int main()
{
  try {
    //freopen("acceptance.xml", "r", stdin);                //debug tools
    algorithm alg;
    alg.parser();
    alg.sort();
    alg.printV();
  }
  catch (std::exception &e) {
    std::cout << e.what();
    return 1;
  }
  return 0;
}
