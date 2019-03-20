#ifndef B8_SQUARE_HPP
#define B8_SQUARE_HPP

#include "shape.hpp"
#include <ostream>

class Square : public Shape
{
public:
  Square(int x = 0, int y = 0);
  void draw(std::ostream &ostream) override;
};

#endif //B8_SQUARE_HPP
