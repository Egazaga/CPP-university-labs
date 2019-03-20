#include <string>
#include <stdexcept>
#include <iostream>

#include "checker.hpp"
#include "redactor.hpp"

void checker(const std::string &str)
{
  char decDivider = std::use_facet<std::numpunct<char> >(std::cout.getloc()).decimal_point();
  if (myIsPunct(str[0]) && !((str[0] == '-') && isdigit(str[1]))) {
    throw std::invalid_argument("Punctuation as a first symbol");
  }
  unsigned int i = 0;
  std::string dash = "---";
  bool lastSymbIsPunct = false;
  bool lastSymbIsComma = false;
  while (i < str.length()) {
    skipSpaces(str, i);
    if (isalpha(str[i])) {
      int wordLength = 0;
      while (isalpha(str[i]) || (str[i] == '-')) {
        if (str[i] == '-') {
          if ((str[i + 1] == '-') && (str[i + 2] != '-')) {
            throw std::invalid_argument("Double dash in a word");
          } else if ((str[i + 1] == '-') && (str[i + 2] == '-')) {
            wordLength--;
            break;
          }
        }
        wordLength++;
        i++;
      }
      if (wordLength > 20) {
        throw std::invalid_argument("Some word is too long");
      }
      lastSymbIsPunct = false;
      lastSymbIsComma = false;
    } else if (isdigit(str[i]) || (((str[i] == '-') || (str[i] == '+')) && isdigit(str[i + 1]))) {
      i++;
      int digitLength = 1;
      while (isdigit(str[i]) || (str[i] == decDivider)) {
        i++;
        digitLength++;
      }
      if (digitLength > 20) {
        throw std::invalid_argument("Some number is too long");
      }
      lastSymbIsPunct = false;
      lastSymbIsComma = false;
    } else if (myIsPunct(str[i])) {
      if ((str[i] == '-') && isalpha(str[i + 1])) {
        throw std::invalid_argument("Hyphen is a first letter of some word");
      }
      if ((str[i] == ',') && !lastSymbIsPunct) {
        lastSymbIsComma = true;
        lastSymbIsPunct = true;
        i++;
      } else if (!lastSymbIsPunct) {
        lastSymbIsPunct = true;
        if (str.substr(i, 3) == "---") {
          i += 3;
        } else {
          i++;
        }
      } else if (lastSymbIsComma && (str.substr(i, 3) == dash)) {        //comma into dash case
        lastSymbIsComma = false;
        i += 3;
      } else {
        throw std::invalid_argument("2 punctuations in a row");
      }
    }
  }
}

void skipSpaces(const std::string &str, unsigned int &i)
{
  while (isblank(str[i]) || (str[i] == '\n') || (str[i] == '\r')) {
    i++;
  }
}
