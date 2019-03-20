#ifndef B7_FUNCTOR_HPP
#define B7_FUNCTOR_HPP

class functor
{
public:
  void operator()(const int &x);

  bool empty = true;
  int max = 0;
  int min = 0;
  double getMean();
  int positive = 0;
  int negative = 0;
  int oddSum = 0;
  int evenSum = 0;
  bool FEqualL = true;

private:
  int first = 0;
  int count = 0;  //for mean
};

#endif //B7_FUNCTOR_HPP
