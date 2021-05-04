#include "functions.hpp"

void dushechkina::fillRandom(double* array, int size)
{
  if (array == nullptr)
  {
    throw std::invalid_argument("Array is nullptr");
  }
  for (int i = 0; i < size; i++)
  {
    array[i] = static_cast< double >(rand()) / RAND_MAX * 2 - 1;
  }
}
