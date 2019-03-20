#include "prog2.hpp"
#include <list>
#include <iostream>
#include <sstream>
#include <memory>
#include <iterator>
#include "shape.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "square.hpp"

void prog2()
{
  std::list< Shape::ptr > shapes;
  std::string str;
  while (std::getline(std::cin, str)) {
    std::stringstream ss;
    ss << str;
    char br1;
    char semicolon;
    char br2;
    std::string shapeName;
    int x;
    int y;
    char end;
    bool blankStr = false;

    ss >> std::skipws >> br1;
    while (br1 != '(' && !ss.eof()) {
      shapeName += br1;
      ss >> br1;
    }
    ss >> x >> semicolon >> y >> br2;
    if (ss.bad() || ss.fail() || br1 != '(' || semicolon != ';' || br2 != ')' ||
       (shapeName != "CIRCLE" && shapeName != "TRIANGLE" && shapeName != "SQUARE")) {
      for (const char &ch : str) {
        if (!isblank(ch)) {
          throw std::invalid_argument("Wrong input");
        }
      }
      blankStr = true;
    }

    if (blankStr) {
      continue;
    }
    ss >> end;    //read 0
    if (!ss.eof()) {
      throw std::invalid_argument("Wrong input");
    }
    if (shapeName == "CIRCLE") {
      std::shared_ptr < Circle > cptr(new Circle(x, y));
      shapes.push_back(cptr);
    } else if (shapeName == "TRIANGLE") {
      std::shared_ptr < Triangle > tptr(new Triangle(x, y));
      shapes.push_back(tptr);
    } else {
      std::shared_ptr < Square > sptr(new Square(x, y));
      shapes.push_back(sptr);
    }
  }             //finished reading

  std::cout << "Original:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape::ptr >(std::cout, "\n"));
  std::cout << "Left-Right:\n";
  shapes.sort([](Shape::ptr &s1, Shape::ptr &s2) {
    return s1->isMoreLeft(s2);
  });
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape::ptr >(std::cout, "\n"));

  std::cout << "Right-Left:\n";
  shapes.sort([](Shape::ptr &s1, Shape::ptr &s2) {
    return !s1->isMoreLeft(s2);
  });
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape::ptr >(std::cout, "\n"));

  std::cout << "Top-Bottom:\n";
  shapes.sort([](Shape::ptr &s1, Shape::ptr &s2) {
    return !s1->isUpper(s2);
  });
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape::ptr >(std::cout, "\n"));

  std::cout << "Bottom-Top:\n";
  shapes.sort([](Shape::ptr &s1, Shape::ptr &s2) {
    return s1->isUpper(s2);
  });
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape::ptr >(std::cout, "\n"));
}
