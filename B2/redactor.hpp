#ifndef B2_REDACTOR_HPP
#define B2_REDACTOR_HPP

#include <string>
#include <vector>

std::vector<std::string> redactor(const std::string &str, unsigned int lineWidth);
void printV(const std::vector<std::string> &vector);
void pushIfFits(std::vector<std::string> &vector, unsigned int &strN, unsigned int lineWidth, std::string &buffer);
void readSpaces(std::string &buffer, const std::string &str, unsigned int &i);
void readPunct(std::string &buffer, const std::string &str, unsigned int &i);
bool myIsPunct(char c);
void readDash(std::string &buffer, const std::string &str, unsigned int &i);

#endif //B2_REDACTOR_HPP
