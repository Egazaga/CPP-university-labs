#include <algorithm>
#include "functor.hpp"

void functor::operator()(const int &x)
{
  if (empty) {
    min = x;
    max = x;
    empty = false;
    first = x;
  }
  min = std::min(x, min);
  max = std::max(x, max);
  count++;
  if (x > 0) {
    positive++;
  } else if (x < 0) {
    negative++;
  }
  if (x%2 == 0) {
    oddSum += x;
  } else {
    evenSum += x;
  }
  FEqualL = (x == first);
}

double functor::getMean()
{
  return (evenSum + oddSum) / static_cast< double >(count);
}
