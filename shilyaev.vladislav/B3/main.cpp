#include <iostream>
#include "task-factorial.hpp"

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cerr << "Invalid argument count";
    return 1;
  }
  std::string task = argv[1];
  if (task == "1") {
    return 2;
  } else if (task == "2") {
    shilyaev::taskFactorial();
  } else {
    std::cerr << "Invalid task number";
    return 1;
  }
}
