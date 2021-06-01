#ifndef HELP_FUNCTIONAL_OBJECTS_H
#define HELP_FUNCTIONAL_OBJECTS_H

#include <vector>

#include "Shape.h"

namespace lysenko
{
  bool isTriangle(const Shape& obj);
  bool isRectangle(const Shape& obj);
  bool isSquare(const Shape& obj);

  struct getNumberOfVertices
  {
    size_t operator()(const lysenko::Shape& obj) const
    {
      return obj.size();
    }
  };

  struct isPentagon
  {
    bool operator()(const lysenko::Shape& obj) const
    {
      size_t sizeOfPentagon = 5;
      return (obj.size() == sizeOfPentagon);
    }
  };

  struct addPoint
  {
    std::vector< Point > operator()(std::vector< Point >& firstPoitsofShapes, const Shape& obj)
    {
      firstPoitsofShapes.push_back(obj[0]);
      return firstPoitsofShapes;
    }
  };

  bool isTriangleOrSquareOrRectangle(const Shape& obj);


  void addTrianglesSquaresAndRectangles(std::vector< Shape >& vect, const Shape& obj);

  void addTypicalShapes(std::vector< Shape >::iterator& begin, int numb, const Shape& obj);

  void shapeSort(std::vector< Shape >& vect);
}

#endif
