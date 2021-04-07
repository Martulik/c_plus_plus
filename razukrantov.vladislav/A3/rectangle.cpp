#include "rectangle.hpp"

razukrantov::Rectangle::Rectangle(double width, double height, const point_t &center):
  width_(width),
  height_(height),
  center_(center)
{
}

double razukrantov::Rectangle::getArea() const
{
  return (width_ * height_);
}

razukrantov::rectangle_t razukrantov::Rectangle::getFrameRect() const
{
  return rectangle_t{width_, height_, center_};
}

void razukrantov::Rectangle::move(const point_t& center)
{
  center_ = center;
}

void razukrantov::Rectangle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}
