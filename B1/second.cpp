#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

#include "tasks.hpp"

void second(const char *fileName)
{
  std::ifstream in(fileName);
  if (!in) {
    throw std::invalid_argument("Error with reading from file");
  }
  in.seekg(0, std::ios_base::end);
  long long int length = in.tellg();
  in.seekg(0);
  if (length == 0) {
    exit(0);
  }
  std::unique_ptr<char[]> arr(new char[length]);
  if (in.is_open()) {
    in.read(arr.get(), length);
  } else {
    throw std::ios_base::failure("Couldn't open file");
  }
  in.close();
  std::vector<char> vector(arr.get(), arr.get() + length);
  for (long long int i = 0; i < length; i++) {
    std::cout << vector[i];
  }
}
