#include "shape.hpp"
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <cmath>

std::istream& lebedeva::operator>>(std::istream& in, Shape& shape)
{
  std::string sVertices;
  std::getline(in >> std::ws, sVertices, ' ');
  if (sVertices.empty())
  {
    return in;
  }
  if (sVertices.back() == '\n')
  {
    throw std::invalid_argument("Invalid input");
  }
  int vertices = std::stoi(sVertices);
  if (vertices < 1)
  {
    throw std::invalid_argument("Invalid number of vertices");
  }

  Shape tempShape;
  tempShape.reserve(vertices);
  std::istream_iterator< Point > inIter(in);
  std::copy_n(inIter, vertices, std::back_inserter(tempShape));
  int size = tempShape.size();
  if (!in || vertices != size)
  {
    throw std::invalid_argument("Invalid number of vertices");
  }
  shape = std::move(tempShape);
  return in;
}

std::ostream& lebedeva::operator<<(std::ostream& out, const Shape& shape)
{
  std::ostream_iterator< Point > outIter(out, " ");
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), outIter);
  return out;
}

bool lebedeva::isTriangle(const Shape& shape)
{
  return (shape.size() == 3);
}

bool lebedeva::isSquare(const Shape& shape)
{
  return (isRectangle(shape) && compareDistances(shape));
}

bool lebedeva::isRectangle(const Shape& shape)
{
  return (shape.size() == 4);
}

bool lebedeva::isPentagon(const Shape& shape)
{
  return (shape.size() == 5);
}

int lebedeva::getDistance(const Point& p1, const Point& p2)
{
  int temp1 = p2.x - p1.x;
  int temp2 = p2.y - p1.y;
  return (temp1 * temp1 + temp2 * temp2);
}

bool lebedeva::compareDistances(const Shape& shape)
{
  int temp1 = getDistance(shape[0], shape[1]);
  int temp2 = getDistance(shape[0], shape[3]);
  return (temp2 == temp1);
}

bool lebedeva::compareDistancesFromOnePoint(const Point centralPoint, const Point p1, const Point p2)
{
  int temp1 = getDistance(centralPoint, p1);
  int temp2 = getDistance(centralPoint, p2);
  return (temp2 == temp1);
}

bool lebedeva::isCrossedSquare(const Shape& shape)
{
  return (isRectangle(shape) && (compareDistancesFromOnePoint(shape[0], shape[1], shape[2]) || compareDistancesFromOnePoint(shape[0], shape[2], shape[3])));
}

bool lebedeva::isCrossedRectangle(const Shape& shape)
{
  return (isRectangle(shape) && checkHypotenuse(shape) && !checkRectangleDistances(shape));
}

bool lebedeva::isSquareAdvanced(const Shape& shape)
{
  return (isRectangle(shape) && (checkSquareDistances(shape) || isCrossedSquare(shape)));
}

bool lebedeva::isRectangleAdvanced(const Shape& shape)
{
  return (isRectangle(shape) && checkHypotenuse(shape));
}

std::vector< int > lebedeva::getAllDistances(const Shape& shape)
{
  int d1 = getDistance(shape[0], shape[1]);
  int d2 = getDistance(shape[1], shape[2]);
  int d3 = getDistance(shape[2], shape[3]);
  int d4 = getDistance(shape[3], shape[0]);
  return { d1, d2, d3, d4 };
}

bool lebedeva::checkSquareDistances(const Shape& shape)
{
  std::vector< int > distances = getAllDistances(shape);
  return (std::adjacent_find(distances.begin(), distances.end(), std::not_equal_to<>()) == distances.end());
}

bool lebedeva::checkRectangleDistances(const Shape& shape)
{
  std::vector< int > distances = getAllDistances(shape);
  return (distances[0] + distances[3] == getDistance(shape[1], shape[3]));
}

bool lebedeva::checkHypotenuse(const Shape& shape)
{
  int a = getDistance(shape[0], shape[1]);
  int b = getDistance(shape[1], shape[2]);
  int c = getDistance(shape[0], shape[2]);
  return ((a + b == c) || (a + c == b) || (b + c == a));
}
