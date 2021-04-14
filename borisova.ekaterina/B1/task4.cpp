#include "tasks.hpp"
#include <vector>
#include "strategies.hpp"
#include "functions.hpp"

int borisova::doTask4(const int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Incorrect number of arguments";
    return 2;
  }
  int size = toInt(argv[3]);
  if (size < 0)
  {
    std::cerr << "Incorrect size\n";
    return 1;
  }
  std::string mode = argv[2];
  std::vector< double >arr(size);
  fillRandom(std::addressof(arr[0]), size);
  print(arr, std::cout);
  std::vector< double > indVec(arr);
  int exitCode = sort< bracketStrategy< double > >(indVec, mode);
  if (!exitCode)
  {
    print(indVec, std::cout);
  }
  return exitCode;
}
