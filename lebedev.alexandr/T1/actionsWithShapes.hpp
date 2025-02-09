#ifndef ACTIONSWITHSHAPES_HPP
#define ACTIONSWITHSHAPES_HPP
#include "shape.hpp"
#include <ostream>

namespace lebedev
{
  double getSumArea(Shape** shps, size_t count);
  void scaleForShapes(Shape** shps, size_t count, point_t scalePoint, double k);
  void printFrameCoordinates(Shape** shps, size_t count, std::ostream& output);
}
#endif
