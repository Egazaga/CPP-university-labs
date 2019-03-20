#include <vector>
#include <iostream>
#include <vector>
#include <iterator>

#include "tasks.hpp"
#include "definitions.hpp"

void third()
{
  std::vector<int> vector1;
  int d = 0;
  while (std::cin >> d) {
    vector1.push_back(d);
  }
  if ((!std::cin.eof()) && (std::cin.fail())) {
    throw std::invalid_argument("Wrong input data. Maybe not integer");
  }
  if (vector1.empty()) {
    exit(0);
  }
  if (vector1.back() != 0) {
    throw std::invalid_argument("No 0 in the end");
  } else {
    vector1.pop_back();
  }
  auto iter = vector1.begin();
  if (vector1.back() == 1) {                        //first variant
    while (iter != vector1.end()) {
      if ((*iter % 2) == 0) {
        vector1.erase(iter);
      } else {
        iter++;
      }
    }
    iter = vector1.begin();
  } else if (vector1.back() == 2) {                 //second variant
    while (iter != vector1.end()) {
      if ((*iter % 3) == 0) {
        iter = vector1.insert(++iter, 3, 1);
        iter += 2;
      }
      iter++;
    }
    iter = vector1.begin();
  }

  detail::printCont(vector1);
}
