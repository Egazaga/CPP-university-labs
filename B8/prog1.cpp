#include "prog1.hpp"

#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>

void prog1()
{
  std::list< double > list;
  list = {std::istream_iterator< double >(std::cin), std::istream_iterator< double >()};
  if (!std::cin.eof() && (std::cin.bad() || std::cin.fail())) {
    throw std::invalid_argument("Wrong input");
  }
  std::transform(list.begin(), list.end(), list.begin(), std::bind1st(std::multiplies<double>(), M_PI));
  std::copy(list.begin(), list.end(), std::ostream_iterator< double >(std::cout, " "));
}
