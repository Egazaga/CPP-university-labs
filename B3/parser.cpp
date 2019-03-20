#include <iostream>
#include <string>

#include "parser.hpp"
#include "queue.hpp"

void parser(const std::string &str)
{
  unsigned int i = 0;
  QueueWithPriority<QueueElement<std::string>> Q;
  while (i < str.length()) {
    if (str.substr(i, 4) == "add ") {
      i += 4;
      QueueElement<std::string> elem;
      elem.data = "";
      elem.priority = LOW;
      if (str.substr(i, 4) == "low ") {
        i += 4;
        elem.priority = ElementPriority::LOW;
      } else if (str.substr(i, 7) == "normal ") {
        i += 7;
        elem.priority = ElementPriority::NORMAL;
      } else if (str.substr(i, 5) == "high ") {
        i += 5;
        elem.priority = ElementPriority::HIGH;
      } else {
        skipToNextCmd(str, i);
      }
      while (str[i] != '\n' && str[i] != '\r') {
        elem.data += str[i];
        i++;
      }
      if (!elem.data.empty()) {
        Q.putElem(elem);
        i++;
      } else {
        skipToNextCmd(str, i);
      }
    } else if (str.substr(i, 10) == "accelerate" && (str[i + 10] == '\n' || str[i + 10] == '\r')) {
      Q.accelerate();
      i += 11;
    } else if (str.substr(i, 3) == "get" && (str[i + 3] == '\n' || str[i + 3] == '\r')) {
      Q.getElem();
      i += 4;
    } else {
      skipToNextCmd(str, i);
    }
  }
}

void skipToNextCmd(const std::string &str, int i) {
  std::cout << "<INVALID COMMAND>" << std::endl;
  while (str[i] != '\n' && str[i] != '\r') {
    i++;
  }
}
