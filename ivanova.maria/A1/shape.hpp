#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "base-types.hpp"

class Shape
{
public:
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t &newPos) = 0;
  virtual void move(double dx, double dy) = 0;
  virtual std::string getName() const = 0;
  virtual point_t getPos() const = 0;
  virtual ~Shape() = default;
};
#endif
