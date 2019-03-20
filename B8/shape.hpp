#ifndef B8_SHAPE_HPP
#define B8_SHAPE_HPP

#include <ostream>
#include <memory>

class Shape
{
public:
  struct point {
    int x, y;
  };
  typedef std::shared_ptr< Shape > ptr;

  Shape(int x = 0, int y = 0);
  bool isMoreLeft(const ptr &shape);
  bool isUpper(const ptr &shape);
  Shape::point getPoint();
  virtual void draw(std::ostream &ostream) = 0;

private:
  int x_, y_;
};

std::ostream &operator << (std::ostream &ostream, const Shape::ptr &shape);

#endif //B8_SHAPE_HPP
