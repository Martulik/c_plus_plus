#ifndef SORT_HPP
#define SORT_HPP

#include <vector>
#include <forward_list>
#include <stdexcept>
#include "strategies.hpp"

namespace lysenko
{
  template< template< typename > typename sortBy, typename container_type >
  void sortBubble(container_type& container,
    bool (*cmp)(const typename container_type::value_type& a, const typename container_type::value_type& b))
  {
    if (cmp == nullptr)
    {
      throw std::invalid_argument("The comparator was not passed");
    }

    typedef sortBy< container_type > sortStrategy;
    typedef typename sortStrategy::iterator iterator;

    for (iterator i = sortStrategy::getBegin(container); i != sortStrategy::getEnd(container); ++i)
    {
      for (iterator j = i; j != sortStrategy::getEnd(container); ++j)
      {
        if (cmp(sortStrategy::getElement(container, j), sortStrategy::getElement(container, i)))
        {
          std::swap(sortStrategy::getElement(container, j), sortStrategy::getElement(container, i));
        }
      }
    }
  }
}
#endif