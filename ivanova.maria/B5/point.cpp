#include "point.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>

namespace iva = ivanova;

bool iva::isRect(const iva::Shape &shp)
{
  return (shp.size() == 4 && iva::checkSidesForRectangle(shp));
}

bool iva::isTriangle(const iva::Shape &shp)
{
  return (shp.size() == 3);
}

bool iva::isSquare(const iva::Shape &shp)
{
  return (isRect(shp) && iva::checkSidesForSquare(shp));
}

bool iva::isPentagon(const iva::Shape &shp)
{
  return (shp.size() == 5);
}


std::istream &ivanova::operator >>(std::istream &in, ivanova::Point &point)
{
  std::string str;
  std::getline(in >> std::ws, str, ')');
  std::istringstream iss(str);
  if (str.empty())
  {
    return in;
  }
  char separator = ' ';
  iss >> separator;
  if (separator != '(')
  {
    std::cerr << "invalid separator";
    exit(1);
  }
  iss >> point.x;
  iss >> separator;
  if (separator == ';')
  {
    iss >> point.y;
    return in;
  }
  else
  {
    std::cerr << "invalid separator";
    exit(1);
  }
}

std::ostream &ivanova::operator <<(std::ostream &out, const ivanova::Point &point)
{
  out << " (" << point.x << "; " << point.y << ")";
  return out;
}

bool iva::checkSidesForRectangle(const Shape &shp)
{
  int ab = std::pow(shp[0].x - shp[1].x, 2) + std::pow(shp[0].y - shp[1].y, 2);
  int bc = std::pow(shp[1].x - shp[2].x, 2) + std::pow(shp[1].y - shp[2].y, 2);
  int cd = std::pow(shp[2].x - shp[3].x, 2) + std::pow(shp[2].y - shp[3].y, 2);
  int da = std::pow(shp[3].x - shp[0].x, 2) + std::pow(shp[3].y - shp[0].y, 2);
  int ac = std::pow(shp[0].x - shp[2].x, 2) + std::pow(shp[0].y - shp[2].y, 2);
  int bd = std::pow(shp[1].x - shp[3].x, 2) + std::pow(shp[1].y - shp[3].y, 2);
  if (ab == cd && bc == da && ac == bd && bd == ab + bc)
  {
    return true;
  }
  return false;
}
bool iva::checkSidesForSquare(const Shape &shp)
{
  int ab = std::pow(shp[0].x - shp[1].x, 2) + std::pow(shp[0].y - shp[1].y, 2);
  int bc = std::pow(shp[1].x - shp[2].x, 2) + std::pow(shp[1].y - shp[2].y, 2);
  int cd = std::pow(shp[2].x - shp[3].x, 2) + std::pow(shp[2].y - shp[3].y, 2);
  int da = std::pow(shp[3].x - shp[0].x, 2) + std::pow(shp[3].y - shp[0].y, 2);
  int ac = std::pow(shp[0].x - shp[2].x, 2) + std::pow(shp[0].y - shp[2].y, 2);
  int bd = std::pow(shp[1].x - shp[3].x, 2) + std::pow(shp[1].y - shp[3].y, 2);
  if (ab == bc && bc == cd && cd == da && ac == bd && bd == ab + bc)
  {
    return true;
  }
  else return false;
}
