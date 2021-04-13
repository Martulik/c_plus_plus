#include "tasks.hpp"

#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

#include "functions.hpp"

void pochernin::task2(const char* fileName)
{
  if (fileName == nullptr)
  {
    throw (std::invalid_argument("Incorrect file name"));
  }
  std::ifstream file(fileName);
  if (!file)
  {
    throw (std::runtime_error("File open error"));
  }

  size_t capacity = 1;
  size_t size = 0;
  std::unique_ptr< char[] > data = std::make_unique< char[] >(capacity);

  while (file)
  {
    file.read(data.get() + size, capacity - size);
    size += file.gcount();
    if (size == capacity)
    {
      capacity *= 2;
      std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
      for (size_t i = 0; i < size; i++)
      {
        temp[i] = std::move(data[i]);
      }
      data = std::move(temp);
    }
  }

  std::vector< char > vec(data.get(), data.get() + size);
  pochernin::print(vec);
}
