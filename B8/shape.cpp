#include "shape.hpp"

Shape::Shape(int x, int y) :
x_(x),
y_(y)
{
}

bool Shape::isMoreLeft(const ptr &shape)
{
  return (this->x_ < shape->x_);
}

bool Shape::isUpper(const ptr &shape)
{
  return (this->y_ < shape->y_);
}

Shape::point Shape::getPoint()
{
  return {x_, y_};
}

std::ostream& operator<<(std::ostream &ostream, const Shape::ptr &shape)
{
  shape->draw(ostream);
  return ostream;
}
