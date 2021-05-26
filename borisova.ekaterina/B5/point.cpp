#include "point.hpp"
#include <iostream>
#include <cmath>

namespace lab = borisova;

double lab::getDistance(const Point& first, const Point& second)
{
  return std::sqrt((first.x - second.x) * (first.x - second.x) +
      (first.y - second.y) * (first.y - second.y));
}

bool lab::isPerpendicularity(const Point& one, const Point& two, const Point three)
{
  return ((one.x - two.x) * (three.x - two.x) +
      (one.y - two.y) * (three.y - two.y)) == 0;
}

std::istream& lab::operator>>(std::istream& in, Point& point)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    throw std::invalid_argument("Empty input\n");
    return in;
  }
  in >> std::skipws;
  if (in.eof())
  {
    return in;
  }
  char sign;
  in >> sign;
  if (sign != '(')
  {
    throw std::invalid_argument("Invalid first literal\n");
  }
  in >> point.x;
  if (in.fail())
  {
    throw std::invalid_argument("Invalid coordinate X\n");
  }
  in >> sign;
  if (sign != ';')
  {
    throw std::invalid_argument("Invalid separate\n");
  }
  in >> point.y;
  if (in.fail())
  {
    throw std::invalid_argument("Invalid coordinate Y\n");
  }
  in >> sign;
  if (sign != ')')
  {
    throw std::invalid_argument("Invalid last literal\n");
  }
  return in;
}

std::ostream& lab::operator<<(std::ostream& out, const Point& point)
{
  out << '(' << point.x << "; " << point.y << ')';
  return out;
}
