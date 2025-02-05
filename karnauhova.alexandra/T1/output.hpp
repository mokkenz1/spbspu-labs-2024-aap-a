#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <string>
#include <iostream>
#include "shape.hpp"
#include "compositeShape.hpp"
namespace karnauhova
{
  void output(std::ostream & out, CompositeShape& shaps, point_t point, double k);
  void scale_point(Shape* object, point_t t, double k);
  void output_points(std::ostream & out, CompositeShape& shaps);
  void output_sum(std::ostream & out, CompositeShape& shaps);
}

#endif
