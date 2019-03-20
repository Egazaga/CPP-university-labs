#ifndef B8_TRIANGLE_HPP
#define B8_TRIANGLE_HPP

#include "shape.hpp"
#include <ostream>

class Triangle : public Shape
{
public:
  Triangle(int x = 0, int y = 0);
  void draw(std::ostream &ostream) override;
};
#endif //B8_TRIANGLE_HPP
