#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace shkurov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& newPos) = 0;
    virtual void move(double x, double y) = 0;
    virtual const char* getName() const = 0;
    void scale(double k);
    double getX() const;
    double getY() const;
    double getHeight() const;
    double getWidth() const;
  protected:
    virtual void scaleFigure(double k) = 0;
  };
}

#endif
