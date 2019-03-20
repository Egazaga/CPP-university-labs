#ifndef B5_ALGORITHM_HPP
#define B5_ALGORITHM_HPP

#include <string>
#include <vector>

struct DataStruct
{
  int key1;
  int key2;
  std::string str;
};

class algorithm
{
public:
  void parser();
  void sort();
  void printV();

private:
  bool isAKey(const std::string &key);
  void skipSpaces();
  std::vector< DataStruct > data;
};

#endif //B5_ALGORITHM_HPP
