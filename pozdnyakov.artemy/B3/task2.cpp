#include "tasks.hpp"
#include <iostream>
#include <algorithm>
#include "container.hpp"

namespace poz = pozdnyakov;

void poz::task2()
{
  poz::FactorialContainer cont;
  std::copy(cont.cbegin(), cont.cend(), std::ostream_iterator< size_t >(std::cout, " "));
  std::cout << '\n';
  std::reverse_copy(cont.cbegin(), cont.cend(), std::ostream_iterator< size_t >(std::cout, " "));
  std::cout << '\n';
}
