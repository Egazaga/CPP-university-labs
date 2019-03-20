#include "triangle.hpp"

#include <ostream>

Triangle::Triangle(int x, int y) : Shape(x, y)
{
}

void Triangle::draw(std::ostream &ostream)
{
  ostream << "TRIANGLE (" << this->getPoint().x << ';' << this->getPoint().y << ')';
}
