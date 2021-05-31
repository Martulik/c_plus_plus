#include "functions.hpp"
#include <iostream>
#include <algorithm>

bool lebedeva::isNumber(const std::string& str)
{
  std::string::const_iterator it = str.begin();
  if (str.length() > 1)
  {
    if ((*it == '+') || (*it == '-'))
    {
      it++;
    }
  }
  return (std::all_of(it, str.end(), ::isdigit));
}

bool lebedeva::isAcceplable(int key)
{
  return ((key > -6) && (key < 6));
}

void lebedeva::print(std::vector< DataStruct > data, std::ostream& out)
{
  std::for_each(data.begin(), data.end(),
    [&](DataStruct& src)
    {
      out << src;
    }
  );
}
