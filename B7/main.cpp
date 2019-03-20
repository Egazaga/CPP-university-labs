#include <iostream>
#include <list>
#include <algorithm>

#include "functor.hpp"

int main()
{
  freopen("data", "r", stdin);                //debug tools
  std::list< int > numbers;
  int i;
  std::cin >> std::skipws;
  while (std::cin >> i) {
    numbers.push_back(i);
  }
  if (std::cin.bad() || std::cin.fail() && !std::cin.eof()) {
    std::cout << "Wrong input";
    return 1;
  }
  functor f = std::for_each(numbers.begin(), numbers.end(), functor());
  if (!f.empty) {
    std::cout << "Max: " << f.max <<
              "\nMin: " << f.min <<
              "\nMean: " << f.getMean() <<
              "\nPositive: " << f.positive <<
              "\nNegative: " << f.negative <<
              "\nOdd Sum: " << f.oddSum <<
              "\nEven Sum: " << f.evenSum <<
              "\nFirst/Last Equal: ";
    if (f.FEqualL) {
      std::cout << "yes";
    } else {
      std::cout << "no";
    }
  } else {
    std::cout << "No Data";
  }
  return 0;
}
