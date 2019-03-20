#ifndef B6_FIGURES_HPP
#define B6_FIGURES_HPP

#include <vector>
#include <list>
#include <string>

struct point
{
  int x, y;
};

class figures {
public:
  typedef std::vector< point > shape;

  void readFigures();
  void countStuff();
  void deletePentagon();
  void fillPointsVector();
  void sort();
  void printStuff();
  bool isRectangle(const figures::shape &shape);
  bool isSquare(const figures::shape &shape);

private:
  std::list< shape > shapes;
  unsigned int vertices = 0;
  unsigned int trianglesCount = 0;
  unsigned int squaresCount = 0;
  unsigned int rectanglesCount = 0;
  std::list< point > points;
};

#endif //B6_FIGURES_HPP
