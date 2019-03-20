#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <forward_list>
#include "definitions.hpp"

void first(const char *sType)
{
  std::vector<int> vector;
  int d = 0;
  while (std::cin >> d) {
    vector.push_back(d);
  }
  if ((!std::cin.eof()) && (std::cin.fail())) {
    throw std::invalid_argument("Wrong input data. Maybe not an integer");
  }
  std::vector<int> vector1 = vector;
  std::forward_list<int> list(vector.begin(), vector.end());
  auto comp = detail::defineComp<int>(sType);
  detail::sort<detail::brackets, std::vector<int>>(vector, comp);
  detail::printCont(vector);
  detail::sort<detail::at, std::vector<int>>(vector1, comp);
  detail::printCont(vector1);
  detail::sort<detail::iter, std::forward_list<int>>(list, comp);
  detail::printCont(list);
}
