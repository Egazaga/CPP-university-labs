#include <list>
#include <iostream>
#include "secondTask.hpp"

void secondTask(const std::list<int> &list)
{
  auto it = list.cbegin();
  auto it2 = list.cend();
  while (it != it2) {
    std::cout << *it << ' ';
    it++;
    if (it != it2) {
      it2--;
      std::cout << *it2 << ' ';
    }
  }
  std::cout << std::endl;
}
