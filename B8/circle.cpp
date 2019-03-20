#include "circle.hpp"

#include <ostream>

Circle::Circle(int x, int y) : Shape(x, y)
{
}
void Circle::draw(std::ostream &ostream)
{
  ostream << "CIRCLE (" << this->getPoint().x << ';' << this->getPoint().y << ')';
}
