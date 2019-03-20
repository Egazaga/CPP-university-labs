#include <iostream>
#include <unordered_map>
#include <string>

#include "interface.hpp"
#include "factorial.hpp"

int main(int argc, char *argv[])
{
  try {
    if (argc != 2) {
      throw std::invalid_argument("Wrong number of arguments");
    } else if (std::stoi(argv[1]) == 1) {
      //freopen("data", "r", stdin);                //debug tools
      Interface interface;
      interface.launchInterface();
    } else if (std::stoi(argv[1]) == 2) {
      Factorial fac;
      std::copy(fac.begin(), fac.end(), std::ostream_iterator<int>(std::cout, " "));
      std::cout << '\n';
      std::copy(std::reverse_iterator<FactorialIterator>(fac.end()),
                std::reverse_iterator<FactorialIterator>(fac.begin()),
                std::ostream_iterator<int>(std::cout, " "));
      std::cout << '\n';
    } else {
      throw std::invalid_argument("Wrong arguments");
    }
  }
  catch (std::exception &e) {
    std::cout << e.what();
    return 1;
  }
  return 0;
}
