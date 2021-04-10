#include <initializer_list>

#include "main-utility.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace lab = savchuk;

const lab::point_t& POS_1 = { 2.3, -7.1 };
const double WIDTH = 6.1;
const double HEIGHT = 9.4;
const lab::point_t& POS_2 = { 42.8, -11.7 };
const double RADIUS = 3.5;

int main()
{
  std::unique_ptr< lab::Shape > r = std::make_unique< lab::Rectangle >(POS_1, WIDTH, HEIGHT);
  lab::testArea(*r);
  lab::testMove(*r, { 6.8, -7.2 });
  lab::testMove(*r, 3.1, 8.6);
  lab::testScale(*r, 7.1);

  std::unique_ptr< lab::Shape > c = std::make_unique< lab::Circle >(POS_2, RADIUS);
  lab::testArea(*c);
  lab::testMove(*c, { -42.3, -26.5 });
  lab::testMove(*c, 5.6, 1.7);
  lab::testScale(*c, 3.2);

  std::initializer_list< std::unique_ptr< lab::Shape > > il{ std::move(r), std::move(c) };
  std::unique_ptr< lab::Shape > comp = std::make_unique< lab::CompositeShape >(il);
  lab::testArea(*comp);
  lab::testMove(*comp, { -4.1, 2.3 });
  lab::testMove(*comp, 3.6, 7.6);
  lab::testScale(*comp, 2.7);
}
