#include "contactsBook.hpp"

#include <iostream>
#include <string>
#include <list>
#include <map>

ContactsBook::ContactsBook() : contacts()
{
  current = contacts.end();
}

void ContactsBook::show()
{
  if (current != contacts.end()) {
    std::cout << current->first << ' ' << current->second << '\n';
  }
}

void ContactsBook::goForward()
{
  if (std::next(current) != contacts.end()) {
    current++;
  }
}

void ContactsBook::goBack()
{
  if (current != contacts.begin()) {
    current--;
  }
}

void ContactsBook::addBefore(std::list <contactType>::iterator pos, ContactsBook::contactType contact)
{
  contacts.insert(pos, contact);
}

void ContactsBook::addAfter(std::list <contactType>::iterator pos, ContactsBook::contactType contact)
{
  contacts.insert(std::next(pos), contact);
}

void ContactsBook::replace(ContactsBook::contactType contact)
{
  if (current != contacts.end()) {
    current->first = contact.first;
    current->second = contact.second;
  }
}

void ContactsBook::addContact(ContactsBook::contactType contact)
{
  contacts.push_back(contact);
}

void ContactsBook::changePosByNSteps(int steps)
{
  if (steps > 0) {
    while (current != std::prev(contacts.end()) || steps != 0) {
      current++;
      steps--;
    }
  } else {
    while (current != contacts.begin() || steps != 0) {
      current--;
      steps--;
    }
  }
}

std::list <ContactsBook::contactType>::iterator ContactsBook::deleteContact(std::list <contactType>::iterator pos)
{
  return contacts.erase(pos);
}

std::list <ContactsBook::contactType>::iterator ContactsBook::begin()
{
  return contacts.begin();
}

std::list <ContactsBook::contactType>::iterator ContactsBook::end()
{
  return contacts.end();
}

unsigned long long int ContactsBook::size()
{
  return contacts.size();
}
