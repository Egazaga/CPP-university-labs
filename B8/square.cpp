#include "square.hpp"

#include <ostream>

Square::Square(int x, int y) : Shape(x, y)
{
}

void Square::draw(std::ostream &ostream)
{
  ostream << "SQUARE (" << this->getPoint().x << ';' << this->getPoint().y << ')';
}
