#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include <string>

#include "shape.hpp"

namespace lysenko
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept;
    explicit CompositeShape(ShapePtr src);

    ~CompositeShape() override = default;

    CompositeShape& operator=(const CompositeShape & src);
    CompositeShape& operator=(CompositeShape && src) noexcept;

    virtual double getArea() const override;
    virtual rectangle_t getFrameRect()const override;
    virtual void move(const point_t & newPos) override;
    virtual void move(double dx, double dy) override;
    virtual std::string getName() const override;

    virtual ShapePtr clone() const override;

    ShapePtr at(size_t index);
    void addShape(const ShapePtr& src);
    void popShape();
    void swap(CompositeShape& other) noexcept;
    void enlargeCapacity(size_t newCapacity);

  private:
    size_t capacity_;
    size_t size_;
    ArrayOfShapes array_;

    virtual void doScale(double k) override;
  };

  double getShapesLeftmostAbscissa(Shape::ShapePtr src);
  double getShapesRightmostAbscissa(Shape::ShapePtr src);
  double getShapesBottomOrdinate(Shape::ShapePtr src);
  double getShapesTopOrdinate(Shape::ShapePtr src);
}

#endif
