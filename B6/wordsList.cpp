#include "wordsList.hpp"

#include <set>
#include <string>
#include <iostream>
#include <iterator>
#include <iomanip>

void wordsList()
{
  std::cin >> std::skipws;
  std::set< std::string > words;
  std::string str;
  while (std::cin >> str) {
    words.insert(str);
  }
  std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
  std::cin >> std::resetiosflags(std::ios_base::skipws);
}
