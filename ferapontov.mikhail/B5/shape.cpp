#include "shape.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include "functions.hpp"

std::istream& ferapontov::operator>>(std::istream& in, Shape& vec)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    size_t size = 0;
    in >> size;
    if (in.fail() || in.get() != ' ')
    {
      in.setstate(std::ios::badbit);
      return in;
    }

    Shape temp;
    std::copy_n(std::istream_iterator< Point >(in), size, std::back_inserter(temp));
    if ((in.fail() && in.eof()) && temp.size() != size)
    {
      in.setstate(std::ios::badbit);
      return in;
    }

    if (in)
    {
      std::swap(vec, temp);
    }
  }
  return in;
}

std::ostream& ferapontov::operator<<(std::ostream& out, const Shape& vec)
{
  std::ostream::sentry sentry(out);
  if (sentry)
  {
    out << vec.size() << ' ';
    std::copy(vec.begin(), vec.end(), std::ostream_iterator< Point >(out, " "));
  }
  return out;
}

bool ferapontov::isTriangle(const Shape& shp)
{
  return shp.size() == 3;
}

bool ferapontov::isSquare(const Shape& shp)
{
  int side1 = calculateVector(shp[0], shp[1]);
  int side2 = calculateVector(shp[0], shp[2]);
  int side3 = calculateVector(shp[0], shp[3]);
  if (side1 == side2)
  {
    return (side3 == calculateVector(shp[1], shp[2]));
  }
  else if (side1 == side3)
  {
    return (side2 == calculateVector(shp[1], shp[3]));
  }
  else if (side2 == side3)
  {
    return (side1 == calculateVector(shp[2], shp[3]));
  }
  return false;
}

bool ferapontov::isRectangle(const Shape& shp)
{
  return shp.size() == 4;
}

bool ferapontov::isPentagon(const Shape& shp)
{
  return shp.size() == 5;
}

bool ferapontov::compare(const Shape& lhs, const Shape& rhs)
{
  if (isRectangle(lhs) && isRectangle(rhs))
  {
    return isSquare(lhs) && !isSquare(rhs);
  }
  return lhs.size() < rhs.size();
}
