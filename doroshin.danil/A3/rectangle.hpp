#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace doroshin
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(udouble_t w, udouble_t h, point_t pos);
    Rectangle(point_t, point_t);
    ~Rectangle() override = default;
    Shape* copy() const override;

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(point_t vec, bool absolute = false) override;
    void scale(double s) override;

  private:
    rectangle_t rect_;
  };
}

#endif // RECTANGLE_HPP
