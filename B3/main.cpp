#include <iostream>

#include "parser.hpp"
#include "queue.hpp"
#include "secondTask.hpp"

int main(int argc, char *argv[])
{
  try {
    if (argc != 2) {
      throw std::invalid_argument("Wrong number of arguments");
    } else if (std::stoi(argv[1]) == 1) {
      //freopen("data", "r", stdin);                //debug tools
      std::string tmp;
      std::string str;
      while (getline(std::cin, tmp)) {
        str += tmp;
        str += '\n';
      }
      parser(str);
    } else if (std::stoi(argv[1]) == 2) {
      //freopen("data3", "r", stdin);               //debug tools
      std::list<int> list;
      std::string tmp;
      int count = 0;
      while (getline(std::cin, tmp, ' ')) {
        for (char c : tmp) {
          if (!isdigit(c) && (c != '\n') && (c != '\r')) {
            throw std::invalid_argument("Not a number");
          }
          if (std::stoi(tmp) > 20 || std::stoi(tmp) < 1) {
            throw std::invalid_argument("Some number is too small or too big");
          }
        }
        count++;
        list.push_back(std::stoi(tmp));
      }
      if (count > 20) {
        throw std::invalid_argument("Too much numbers");
      }
      if (!list.empty()) {
        secondTask(list);
      }
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
