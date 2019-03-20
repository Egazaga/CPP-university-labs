#include <iostream>
#include <string>
#include <vector>

#include "redactor.hpp"

std::vector<std::string> redactor(const std::string &str, const unsigned int lineWidth)
{
  char decDivider = std::use_facet<std::numpunct<char> >(std::cout.getloc()).decimal_point();
  unsigned int strN = 0;
  std::vector<std::string> vector(1);
  std::string buffer;
  unsigned int i = 0;
  while (i < str.length()) {
    readSpaces(buffer, str, i);
    if (isalpha(str[i])) {                                                      //if a word has started
      while (isalpha(str[i]) || ((str[i] == '-') && (str[i + 1] != '-'))) {     //while it's a word and not a '---'
        buffer += str[i];                                                       //add it to buffer
        i++;
      }
      readSpaces(buffer, str, i);
      if (myIsPunct(str[i])) {                                                  //punctuation after a word (without '+')
        if (buffer.back() == ' ') {                                             //no space between a word
          buffer.pop_back();                                                    //and punctuation
        }
        readPunct(buffer, str, i);
      }
    } else if (isdigit(str[i]) || (str[i] == '-') || str[i] == '+') {           //if a number has started
      buffer += str[i];                                                         //read '-', '+' or the first digit
      i++;
      while (isdigit(str[i]) || (str[i] == decDivider)) {                       //read the whole number
        buffer += str[i];
        i++;
      }
      if (buffer.back() != decDivider) {                                        //read punctuation after a number,
        readSpaces(buffer, str, i);                                             //except if we've already read a '.',
        if (myIsPunct(str[i])) {                                                //which will be the end of this buffer
          if (buffer.back() == ' ') {                                           //no space between a number
            buffer.pop_back();                                                  //and punctuation
          }
          readPunct(buffer, str, i);
        }
      }
    }
    pushIfFits(vector, strN, lineWidth, buffer);
  }
  return vector;
}

void printV(const std::vector<std::string> &vector)
{
  for (unsigned int i = 0; i != vector.size(); i++) {
    for (unsigned int j = 0; j != vector[i].length(); j++) {
      std::cout << vector[i][j];
    }
    std::cout << std::endl;
  }
}

void pushIfFits(std::vector<std::string> &vector, unsigned int &strN, const unsigned int lineWidth, std::string &buffer)
{
  bool spaceFlag = false;
  if (buffer.back() == ' ') {
    spaceFlag = true;
    buffer.pop_back();
  }
  if ((vector[strN].length() + buffer.length()) > lineWidth) {     //if doesn't fit in old string
    if (buffer.front() == ' ') {                                    //remove a space in front
      buffer.erase(0, 1);
    }
    vector.resize(++strN + 1);                                      //add a new string to vector
  }
  vector[strN] += buffer;                                           //push buffer into a string
  buffer.clear();
  if (spaceFlag) {
    buffer.push_back(' ');
  }
}

void readSpaces(std::string &buffer, const std::string &str, unsigned int &i)  //if there is a space or tabulation
{                                                                              //push one and skip all others
  if (isblank(str[i]) || (str[i] == '\n') || str[i] == '\r') {
    if (buffer.back() != ' ') {
      buffer += ' ';
      i++;
    }
    while (isblank(str[i]) || (str[i] == '\n') || str[i] == '\r') {
      i++;
    }
  }
}

void readPunct(std::string &buffer, const std::string &str, unsigned int &i)
{
  if (str[i] == ',') {                                                      //',' then '---' case
    buffer += str[i];                                                       //add ',' to a buffer
    i++;
    readSpaces(buffer, str, i);
    if ((str[i] == '-') && (str[i + 1] == '-')) {
      readDash(buffer, str, i);
    }
  } else if ((str[i] == '-') && (str[i + 1] == '-')) {                      //'---' case
    readDash(buffer, str, i);
  } else if (str[i] != '-') {                                               //it's any other punctuation, except
    buffer.push_back(str[i]);                                               //a '-' before a digit
    i++;
  }
  if (buffer.back() != ' ') {
    buffer.push_back(' ');                                                  //always space after punctuation
  }
}

void readDash(std::string &buffer, const std::string &str, unsigned int &i)
{
  if (buffer.back() != ' ') {
    buffer += ' ';
  }
  buffer += str.substr(i, 3);                                               //add '---' to a buffer
  i += 3;
}

bool myIsPunct(const char c)
{
  return (c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == ';' || c == '-');
}
