#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "redactor.hpp"
#include "checker.hpp"

int main(int argc, char *argv[])
{
  //freopen("data3", "r", stdin);              //debug tools
  try {
    unsigned int lineWidth = 0;
    if (argc > 3) {
      throw std::invalid_argument("Too many arguments");
    } else if (argc == 1) {
      lineWidth = 40;
    } else {
      if (std::stoi(argv[2]) >= 25) {
        lineWidth = std::stoi(argv[2]);
      } else {
        throw std::invalid_argument("Incorrect line width");
      }
    }
    std::string str;
    std::cin >> std::noskipws;
    std::copy(std::istream_iterator<char>(std::cin), std::istream_iterator<char>(), std::back_inserter(str));
    checker(str);
    std::vector<std::string> vector = redactor(str, lineWidth);
    if (!vector[0].empty()) {               //whitespace or empty input
      printV(vector);
    }
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
