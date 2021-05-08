#include "phonebook.hpp"
#include <iostream>

void diurdeva::Phonebook::pushBack(const record_t& rec)
{
  return list_.push_back(rec);
}

bool diurdeva::Phonebook::empty() const
{
  return list_.empty();
}

diurdeva::Phonebook::iterator diurdeva::Phonebook::begin()
{
  return list_.begin();
}

diurdeva::Phonebook::iterator diurdeva::Phonebook::end()
{
  return list_.end();
}

diurdeva::Phonebook::iterator diurdeva::Phonebook::next(iterator iter) const
{
  if (std::next(iter) != list_.end())
  {
    return ++iter;
  }
  else
  {
    return iter;
  }
}

diurdeva::Phonebook::iterator diurdeva::Phonebook::prev(iterator iter) const
{
  if (iter != list_.begin())
  {
    return --iter;
  }
  else
  {
    return iter;
  }
}

diurdeva::Phonebook::iterator diurdeva::Phonebook::insert(iterator iter, const record_t& rec)
{
  return list_.insert(iter, rec);
}

diurdeva::Phonebook::iterator diurdeva::Phonebook::remove(iterator iter)
{
  return list_.erase(iter);
}

diurdeva::Phonebook::iterator diurdeva::Phonebook::replace(iterator iter, record_t& src)
{
  *iter = src;
  return iter;
}

diurdeva::Phonebook::iterator diurdeva::Phonebook::move(iterator iter, int n)
{
  if (n >= 0)
  {
    while (std::next(iter) != list_.end() && (n > 0))
    {
      iter = next(iter);
      --n;
    }
  }
  else
  {
    while (iter != list_.begin() && (n < 0))
    {
      iter = prev(iter);
      ++n;
    }
  }
  return iter;
}
