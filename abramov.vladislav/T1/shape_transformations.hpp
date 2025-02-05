#ifndef SHAPE_TRANSFORMATIONS_HPP
#define SHAPE_TRANSFORMATIONS_HPP
#include <cstddef>
#include <iostream>
#include <iomanip>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "complexquad.hpp"
#include "shape.hpp"
#include "composite-shape.hpp"

namespace abramov
{
  void getShapes(std::istream &in, Composite &shapes, point_t &p, double &k, bool &flag);
  void scaleFigure(Shape *s, const point_t &p, double k);
  void scaleFigures(Composite &shapes, const point_t &p, double k, size_t i);
  void unsafeScaleFigure(Shape *s, const point_t &p, double k);
  void printShapes(std::ostream &out, const Composite &shapes, size_t i);
}
#endif
