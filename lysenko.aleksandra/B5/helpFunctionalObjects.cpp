#include "helpFunctionalObjects.h"

#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

namespace lysenko
{
  static int getDeltaFromFirstPoint(bool abscissa, const Shape& obj, const Point& pnt)
  {
    if (abscissa)
    {
      return pnt.x - obj[0].x;
    }
    return pnt.y - obj[0].y;
  }

  double getDistanceFromFirstPoint(const Shape& obj, const Point& pnt)
  {
    double deltaX = getDeltaFromFirstPoint(0, obj, pnt);
    double deltaY = getDeltaFromFirstPoint(1, obj, pnt);

    return std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));
  }

  struct fillTheVect
  {
    std::vector< double > operator()(std::vector< double >& distances, const double& dist)
    {
      distances.push_back(dist);
      return distances;
    }
  };

  static std::vector< double > getSortedVectOfDistancesFromFirstPoint(const Shape& obj)
  {
    namespace plc = std::placeholders;
    std::vector< double > distances;
    if (obj.size() == 4)
    {
      if (!((obj[0] == obj[1]) && (obj[0] == obj[2]) && (obj[0] == obj[3])))
      {
        auto fill = std::bind(fillTheVect(), plc::_1, std::bind(getDistanceFromFirstPoint, obj, plc::_2));
        std::vector< double > trueDist = std::accumulate(obj.begin() + 1, obj.end(), std::vector< double >(), fill);

        std::stable_sort(trueDist.begin(), trueDist.end());
        std::swap(distances, trueDist);
      }
      else
      {
        std::vector< double > trueDist(3);
        std::swap(distances, trueDist);
      }
    }
    return distances;
  }
}

bool lysenko::isTriangle(const lysenko::Shape& obj)
{
  return (obj.size() == 3);
}

bool lysenko::isRectangle(const lysenko::Shape& obj)
{
  std::vector< double > distances = getSortedVectOfDistancesFromFirstPoint(obj);
  return ((!(distances.empty())) && (distances[2] == std::sqrt(std::pow(distances[0], 2) + std::pow(distances[1], 2))));
}

bool lysenko::isSquare(const lysenko::Shape& obj)
{
  std::vector< double > distances = getSortedVectOfDistancesFromFirstPoint(obj);
  bool isRectangle = ((!(distances.empty())) && (distances[2] == std::sqrt(std::pow(distances[0], 2) + std::pow(distances[1], 2))));
  if (isRectangle)
  {
    return (distances[0] == distances[1]);
  }
  return 0;
}

bool lysenko::isPentagon(const Shape& obj)
{
  return (obj.size() == 5);
}

void lysenko::shapeSort(std::vector< Shape >& vect)
{
  namespace plc = std::placeholders;

  std::vector< Shape > sortedOne;
  std::vector< Shape > triangles;
  std::vector< Shape > squares;
  std::vector< Shape > rectangles;
  std::vector< Shape > others;

  std::for_each(vect.begin(), vect.end(), std::bind(doSort, triangles, squares, rectangles, others, plc::_1));

  sortedOne.insert(sortedOne.end(), triangles.begin(), triangles.end());
  sortedOne.insert(sortedOne.end(), squares.begin(), squares.end());
  sortedOne.insert(sortedOne.end(), rectangles.begin(),rectangles.end());
  sortedOne.insert(sortedOne.end(), others.begin(), others.end());
  
  std::swap(sortedOne, vect);
}

void lysenko::doSort(std::vector< Shape >& tri, std::vector< Shape >& sq, std::vector< Shape >& rect, std::vector< Shape >& oth, Shape& shp)
{
  if (isRectangle(shp))
  {
    tri.push_back(shp);
    return;
  }
  if (isSquare(shp))
  {
    sq.push_back(shp);
    return;
  }
  if (isRectangle(shp))
  {
    rect.push_back(shp);
    return;
  }
  oth.push_back(shp);
}
