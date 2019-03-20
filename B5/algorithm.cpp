#include "algorithm.hpp"

#include <string>
#include <iostream>
#include <algorithm>

bool algorithm::isAKey(const std::string &key)
{
  for (char c : key) {
    if (!isdigit(c) && c != '+' && c != '-') {
      return false;
    }
  }
  return (std::stoi(key) <= 5 && std::stoi(key) >= -5);
}

void algorithm::skipSpaces()
{
  while (std::cin.peek() == ' ') {
    getchar();
  }
}

void algorithm::parser()
{
  std::string tmp[3];
  while (getline(std::cin, tmp[0], ',')) {
    skipSpaces();
    getline(std::cin, tmp[1], ',');
    skipSpaces();
    getline(std::cin, tmp[2]);
    if (isAKey(tmp[0]) && isAKey(tmp[1]) && !tmp[2].empty()) {
      data.resize(data.size() + 1, {std::stoi(tmp[0]), std::stoi(tmp[1]), tmp[2]});
    } else {
      throw std::invalid_argument("Incorrect keys");
    }
  }
}

void algorithm::sort()
{
  if (!data.empty()) {
    std::sort(data.begin(), data.end(), [](DataStruct a, DataStruct b)
    {
      if (a.key1 < b.key1) {
        return true;
      } else if (a.key1 == b.key1) {
        if (a.key2 < b.key2) {
          return true;
        } else if (a.key2 == b.key2) {
          if (a.str.length() < b.str.length()) {
            return true;
          }
        }
      }
      return false;
    });
  }
}

void algorithm::printV()
{
  for (DataStruct dataStruct : data) {
    std::cout << dataStruct.key1 << ',' << dataStruct.key2 << ',' << dataStruct.str << '\n';
  }
}
