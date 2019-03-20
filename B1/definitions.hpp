#ifndef B1_DEFINITIONS_HPP
#define B1_DEFINITIONS_HPP

#include <cstddef>
#include <cstring>
#include <string>
#include <iterator>
#include <iostream>
#include <functional>

namespace detail {
  template<typename C>
  struct brackets
  {
    typedef std::size_t indexType;

    static typename C::reference getElem(C &container, indexType i)
    {
      return container[i];
    }

    static indexType getBegin(C &)
    {
      return 0;
    }

    static indexType getEnd(C &container)
    {
      return container.size();
    }
  };

  template<typename C>
  struct at
  {
    typedef std::size_t indexType;

    static typename C::reference getElem(C &container, indexType i)
    {
      return container.at(i);
    }

    static indexType getBegin(C &)
    {
      return 0;
    }

    static indexType getEnd(C &container)
    {
      return container.size();
    }
  };

  template<typename C>
  struct iter
  {
    typedef typename C::iterator indexType;

    static typename C::reference getElem(C &, indexType i)
    {
      return *i;
    }

    static indexType getBegin(C &container)
    {
      return container.begin();
    }

    static indexType getEnd(C &container)
    {
      return container.end();
    }
  };

  template<template<typename C> class traits, typename C, class Compare>
  void sort(C &container, Compare comp)
  {
    typedef typename traits<C>::indexType index;
    for (index i = traits<C>::getBegin(container); i != traits<C>::getEnd(container); i++) {
      for (index j = i; j != traits<C>::getEnd(container); j++) {
        if (comp(traits<C>::getElem(container, i), traits<C>::getElem(container, j))) {
          std::swap(traits<C>::getElem(container, i), (traits<C>::getElem(container, j)));
        }
      }
    }
  }

  template<typename C>
  void printCont(C &container)
  {
    for (typename C::iterator it = container.begin(); it != container.end(); it++) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }

  template<typename T>
  std::function<bool(const T &, const T &)> defineComp(const char *sType)
  {
    if (std::strcmp(sType, "ascending") == 0) {
      return std::greater<T>();
    } else if (std::strcmp(sType, "descending") == 0) {
      return std::less<T>();
    } else {
      throw std::invalid_argument("Wrong sorting type");
    }
  }
}

#endif //B1_DEFINITIONS_HPP
