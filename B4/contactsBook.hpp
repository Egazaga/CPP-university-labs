#ifndef B4_CONTACTSBOOK_HPP
#define B4_CONTACTSBOOK_HPP

#include <string>
#include <list>

class ContactsBook
{
public:
  typedef std::pair<std::string, std::string> contactType;

  ContactsBook();
  void show();
  void goForward();
  void goBack();
  void addBefore(std::list <contactType>::iterator pos, contactType contact);
  void addAfter(std::list <contactType>::iterator pos, contactType contact);
  void replace(contactType contact);
  void addContact(contactType contact);
  void changePosByNSteps(int steps);
  unsigned long long int size();
  std::list <contactType>::iterator deleteContact(std::list <contactType>::iterator pos);
  std::list <contactType>::iterator begin();
  std::list <contactType>::iterator end();

private:
  std::list <contactType> contacts;
  std::list <contactType>::iterator current;
};

#endif //B4_CONTACTSBOOK_HPP
