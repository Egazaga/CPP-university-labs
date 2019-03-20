#ifndef B4_INTERFACE_HPP
#define B4_INTERFACE_HPP

#include <map>
#include <string>

#include "contactsBook.hpp"

std::istream& operator>>(std::istream& is, ContactsBook::contactType &contact);

class Interface
{
public:
  Interface();
  void launchInterface();
  bool markExists(std::string mark);

private:
  std::map<std::string, std::list<ContactsBook::contactType>::iterator> marks;
  ContactsBook book;
};

#endif //B4_INTERFACE_HPP
