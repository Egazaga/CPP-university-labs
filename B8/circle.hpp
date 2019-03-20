#ifndef B8_CIRCLE_HPP
#define B8_CIRCLE_HPP

#include "shape.hpp"

#include <ostream>

class Circle : public Shape
{
public:
  Circle(int x = 0, int y = 0);
  void draw(std::ostream &ostream) override;
};

#endif //B8_CIRCLE_HPP
