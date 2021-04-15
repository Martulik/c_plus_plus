#ifndef B1_TASK3_CPP
#define B1_TASK3_CPP

#include "tasks.hpp"

#include <vector>
#include <istream>
#include "functions.hpp"

namespace iva = ivanova;
int iva::task3()
{
  std::vector< int > vector;
  int element = 0;
  while (std::cin >> element)
  {
    if (element == 0)
    {
      break;
    }
    vector.push_back(element);
  }
  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << ("Incorrect data!");
    exit(1);
  }
  if (element != 0)
  {
    std::cerr << ("The last element must be zero!");
    exit(1);
  }
  if (vector.empty())
  {
    return 0;
  }
  if (vector.back() == 1)
  {
    for (std::vector< int >::iterator i = vector.begin(); i != vector.end(); i++)
    {
      if (*i % 2 == 0)
      {
       i++;
      }
      else vector.erase(i);
    }
  }
  else if (vector.back() == 2)
  {
    for (std::vector< int >::iterator i = vector.begin(); i != vector.end(); i++)
    {
      if (*i % 3 == 0)
      {
        i = vector.insert(++i, 3, 1) + 2;
      }
    }
  }
  iva::print(vector, std::cout);
  return 0;
}
#endif
