#ifndef B3_QUEUE_HPP
#define B3_QUEUE_HPP

#include <iostream>
#include <array>
#include <list>

enum ElementPriority
{
  LOW,
  NORMAL,
  HIGH
};

template < typename T >
struct QueueElement
{
  T data;
  ElementPriority priority;
};

template <typename T>
class QueueWithPriority
{
public:
  void putElem(const T &element);
  void getElem();
  void accelerate();

private:
  std::list<T> highPriorityList;
  std::list<T> normalPriorityList;
  std::list<T> lowPriorityList;
};

template<typename T>
void QueueWithPriority<T>::putElem(const T &element)
{
  if (element.priority == LOW) {
    lowPriorityList.push_back(element);
  } else if (element.priority == NORMAL) {
    normalPriorityList.push_back(element);
  } else if (element.priority == HIGH) {
    highPriorityList.push_back(element);
  }
}

template<typename T>
void QueueWithPriority<T>::getElem()
{
  if (!highPriorityList.empty()) {
    std::cout << highPriorityList.front().data << '\n';
    highPriorityList.pop_front();
  } else if (!normalPriorityList.empty()) {
    std::cout << normalPriorityList.front().data << '\n';
    normalPriorityList.pop_front();
  } else if (!lowPriorityList.empty()) {
    std::cout << lowPriorityList.front().data << '\n';
    lowPriorityList.pop_front();
  } else {
    std::cout << "<EMPTY>\n";
  }
}

template<typename T>
void QueueWithPriority<T>::accelerate()
{
  highPriorityList.splice(highPriorityList.end(), lowPriorityList);
}

#endif //B3_QUEUE_HPP
