#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>

#include "tasks.hpp"
#include "definitions.hpp"

void fillRandom(double *array, long long int size)
{
  srand(time(0));
  for (int i = 0; i < size; i++) {
    array[i] = (rand() % 20 - 10) * 0.1;
  }
}

void fourth(const char *sType, const char *length)
{
  if (std::stoi(length) <= 0) {
    throw std::invalid_argument("Wrong length");
  }
  unsigned long long int vSize = std::stoi(length);
  std::vector<double> vector1(vSize);
  fillRandom(&vector1[0], vSize);
  auto comp = detail::defineComp<double>(sType);
  detail::printCont(vector1);
  detail::sort<detail::brackets>(vector1, comp);
  detail::printCont(vector1);
}
