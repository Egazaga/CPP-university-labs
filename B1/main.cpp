#include <iostream>
#include <string>
#include "tasks.hpp"

int main(int argc, char *argv[])
{
  try {
    if (argc < 2) {
      std::cerr << "Not enough arguments" << std::endl;
      return 1;
    }
    switch (std::stoi(argv[1])) {
      case 1:
        if (argc != 3) {
          throw std::invalid_argument("Invalid number of arguments");
        } else {
          first(argv[2]);
        }
        break;
      case 2:
        if (argc != 3) {
          throw std::invalid_argument("Invalid number of arguments");
        } else {
          second(argv[2]);
        }
        break;
      case 3:
        if (argc != 2) {
          throw std::invalid_argument("Invalid number of arguments");
        } else {
          third();
        }
        break;
      case 4:
        if (argc != 4) {
          throw std::invalid_argument("Invalid number of arguments");
        } else {
          fourth(argv[2], argv[3]);
        }
        break;
      default:
        throw std::invalid_argument("Invalid number of arguments");
    }
  }

  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
