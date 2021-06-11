#include "tasks.hpp"
#include <iterator>
#include <iostream>
#include <algorithm>
#include "functions.hpp"
#include "shape.hpp"

void lebedeva::doTask2(std::istream& in, std::ostream& out)
{
  std::istream_iterator< Shape > inIterFirst(in);
  std::istream_iterator< Shape > inIterLast;
  std::vector< Shape > shapes(inIterFirst, inIterLast);
  if (!in && !in.eof())
  {
    throw std::runtime_error("Input error");
  }

  ShapesSpecifics info = countShapes(shapes);

  //removePentagons(shapes);
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());

  Shape frontPoints = getFrontPoints(shapes);

  //sortShapes(shapes);
  std::sort(shapes.begin(), shapes.end(), hasMoreVertices);

  printInfo(out, info);
  out << '\n';
  printPoints(out, frontPoints);
  out << '\n';
  printShapes(out, shapes);
}
