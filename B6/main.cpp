#include <iostream>
#include <ctime>
#include "wordsList.hpp"
#include "figures.hpp"

int main(int argc, char *argv[])
{
  try {
    freopen("data2", "r", stdin);                //debug tools
    if (argc != 2) {
      throw std::invalid_argument("Wrong number of arguments");
    } else if (std::stoi(argv[1]) == 1) {
      wordsList();
    } else if (std::stoi(argv[1]) == 2) {
      figures test;
      test.readFigures();
      test.countStuff();
      test.deletePentagon();
      test.fillPointsVector();
      test.sort();
      std::cout << clock() << '\n';
      test.printStuff();
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
