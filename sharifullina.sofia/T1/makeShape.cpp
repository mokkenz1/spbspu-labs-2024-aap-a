#include "makeShape.hpp"
#include <stdexcept>

sharifullina::Rectangle* sharifullina::makeRectangle(std::istream& in)
{
  double params[4] = {0.0, 0.0, 0.0, 0.0};
  in >> params[0] >> params[1] >> params[2] >> params[3];
  point_t lowLeft = {params[0], params[1]};
  point_t uppRight = {params[2], params[3]};
  if (lowLeft.x >= uppRight.x || lowLeft.y >= uppRight.y)
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
  sharifullina::Rectangle* rect = new sharifullina::Rectangle(lowLeft, uppRight);
  return rect;
}

sharifullina::Ring* sharifullina::makeRing(std::istream& in)
{
  double params[4] = {0.0, 0.0, 0.0, 0.0};
  in >> params[0] >> params[1] >> params[2] >> params[3];
  point_t center = {params[0], params[1]};
  double innerRadius = params[2];
  double outerRadius = params[3];
  if (innerRadius <= 0 || outerRadius <= 0 || innerRadius >= outerRadius)
  {
    throw std::invalid_argument("Incorrect radius");
  }
  sharifullina::Ring* rin9 = new sharifullina::Ring(center, r1, r2);
  return rin9;
}

sharifullina::Circle* sharifullina::makeCircle(std::istream& in)
{
  double params[3] = {0.0, 0.0, 0.0};
  in >> params[0] >> params[1] >> params[2];
  point_t center = {params[0], params[1]};
  double radius = params[2];
  if (radius <= 0)
  {
    throw std::invalid_argument("Incorrect radius");
  }
  sharifullina::Circle* circl = new sharifullina::Circle(center, r);
  return circl;
}

sharifullina::Ellipse* sharifullina::makeEllipse(std::istream& in)
{
  double params[4] = {0.0, 0.0, 0.0, 0.0};
  in >> params[0] >> params[1] >> params[2] >> params[3];
  point_t center = {params[0], params[1]};
  double radiusX = params[2];
  double radiusY = params[3];
  if (radiusX <= 0 || radiusY <= 0)
  {
    throw std::invalid_argument("Incorrect radius");
  }
  sharifullina::Ellipse* ellips = new sharifullina::Ellipse(center, r2, r1);
  return ellips;
}
