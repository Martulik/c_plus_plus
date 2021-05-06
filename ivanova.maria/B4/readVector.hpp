#ifndef B4_READVECTOR_HPP
#define B4_READVECTOR_HPP

#include <vector>
#include <iostream>
#include <string>

#include "struct.hpp"
#include "tools.cpp"

namespace ivanova
{
  template < typename T > int readVector(std::vector < T > &vector )
  {
    std::string str;
    while (std::getline(std::cin, str))
    {
      if (std::cin.fail())
      {
        std::cerr << "Read fail";
      }
      else if (str.empty())
      {
        return 0;
      }
      else
      {
        getVector(str, vector);
      }
    }
    if (!std::cin.eof())
    {
      std::cerr << "Failed reading";
      return 1;
    }
    return 0;
  }
}
#endif
