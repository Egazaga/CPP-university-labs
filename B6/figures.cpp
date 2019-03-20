#include "figures.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

void figures::readFigures()
{
  std::string str;
  while (std::getline(std::cin, str)) {
    std::vector<point> tmp;
    std::stringstream ss;
    ss << str;
    char br1;
    char semicolon;
    char br2;
    std::size_t pointsCount;
    int x;
    int y;
    char end;
    bool blankStr = false;

    ss >> pointsCount;
    for (std::size_t i = 0; i < pointsCount; ++i) {
      ss >> std::skipws >> br1 >> x >> semicolon >> y >> br2;
      if (ss.bad() || ss.fail() || br1 != '(' || semicolon != ';' || br2 != ')') {
        for (const char &c: str) {
          if (!isblank(c)) {
            throw std::invalid_argument("Wrong input");
          }
        }
        blankStr = true;
        break;
      } else {
        tmp.push_back({x, y});
      }
    }

    if (blankStr) {
      continue;
    }
    ss >> end;    //read 0
    if (!ss.eof()) {
      throw std::invalid_argument("Wrong input");
    }
    if (tmp.size() == pointsCount) {
      shapes.push_back(tmp);
    } else {
      throw std::invalid_argument("Wrong input");
    }
  }
}

void figures::countStuff()
{
  for (const shape &s : shapes) {
    unsigned int size = s.size();
    vertices += size;
    if (size == 3) {
      trianglesCount++;
    } else if (size == 4) {
      if (isRectangle(s)) {
        rectanglesCount++;
        if (isSquare(s)) {
          squaresCount++;
        }
      }
    }
  }
}

void figures::deletePentagon()
{
  shapes.remove_if([](const shape &s)
                   { return s.size() == 5; });
}

void figures::fillPointsVector()
{
  for (const shape &s : shapes) {
    points.push_back(s[0]);
  }
}

void figures::sort()
{
  shapes.sort([this](const shape &s1, const shape &s2)
              {
                if (s1.size() == 3) {
                  return true;
                } else if (s2.size() == 3) {
                  return false;
                }
                if (isSquare(s1)) {
                  return true;
                }
                if (isSquare(s2)) {
                  return false;
                }
                return isRectangle(s1);
              });
}

void figures::printStuff()
{
  std::cout << "Vertices: " << vertices << "\nTriangles: " << trianglesCount << "\nSquares: " << squaresCount
            << "\nRectangles: " << rectanglesCount << "\nPoints:";
  for (const point &p : points) {
    std::cout << " (" << p.x << ';' << p.y << ')';
  }
  std::cout << "\nShapes:\n";
  for (const shape &s: shapes) {
    std::cout << s.size();
    for (const point &p : s) {
      std::cout << " (" << p.x << ';' << p.y << ')';
    }
    std::cout << '\n';
  }
}

bool figures::isRectangle(const figures::shape &shape)
{
  if (shape.size() != 4u) {
    return false;
  }
  long diagonal1 = std::pow((shape[0].x - shape[2].x), 2) + std::pow((shape[0].y - shape[2].y), 2);
  long diagonal2 = std::pow((shape[1].x - shape[3].x), 2) + std::pow((shape[1].y - shape[3].y), 2);
  return diagonal1 == diagonal2;
}

bool figures::isSquare(const figures::shape &shape)
{
  if (!isRectangle(shape)) {
    return false;
  }
  double distance = std::pow((shape[0].x - shape[3].x), 2) + std::pow((shape[0].y - shape[3].y), 2);
  for (std::size_t i = 0; i < 2; i++) {
    double current_distance = std::pow((shape[i].x - shape[i + 1].x), 2) + std::pow((shape[i].y - shape[i + 1].y), 2);
    if (current_distance != distance) {
      return false;
    }
  }
  return true;
}
