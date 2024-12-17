#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace kizhin {
  class Rectangle;
}

class kizhin::Rectangle: public Shape
{
public:
  Rectangle(double, double, const point_t&);

  rectangle_t getFrameRect() const override;
  double getArea() const override;

  void move(const point_t&) override;
  void move(double, double) override;
  void scale(double) override;

private:
  rectangle_t data_;
};

#endif

