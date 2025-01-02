#include "regular.hpp"
#include <cmath>
#include <stdexcept>
#include <limits>

namespace
{
  bool isRightTriangle(maslevtsov::point_t p1, maslevtsov::point_t p2, maslevtsov::point_t p3)
  {
    double sqrLength1 = std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2);
    double sqrLength2 = std::pow(p2.x - p3.x, 2) + std::pow(p2.y - p3.y, 2);
    double sqrLength3 = std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2);
    return (sqrLength1 != 0 || sqrLength2 != 0 || sqrLength3 != 0) &&
           ((sqrLength1 + sqrLength2 == sqrLength3) || (sqrLength2 + sqrLength3 == sqrLength1) ||
            (sqrLength1 + sqrLength3 == sqrLength2));
  }

  bool isRightSize(std::size_t nVertices, double smallRadius, double bigRadius)
  {
    return std::abs((std::cos(M_PI / nVertices)) - (smallRadius / bigRadius)) < 1e-10;
  }

  std::size_t getNVertices(maslevtsov::point_t center, maslevtsov::point_t pnt2, maslevtsov::point_t pnt3)
  {
    double sqrLength1 = std::pow(center.x - pnt2.x, 2) + std::pow(center.y - pnt2.y, 2);
    double sqrLength2 = std::pow(pnt2.x - pnt3.x, 2) + std::pow(pnt2.y - pnt3.y, 2);
    double sqrLength3 = std::pow(center.x - pnt3.x, 2) + std::pow(center.y - pnt3.y, 2);
    double sqrHypotenuse = std::max(std::max(sqrLength1, sqrLength2), sqrLength3);
    double sqrSmallRadius = std::min(std::min(sqrLength1, sqrLength2), sqrLength3);
    std::size_t nVertices = M_PI / std::acos(std::sqrt(sqrSmallRadius / sqrHypotenuse));
    return nVertices;
  }

  maslevtsov::point_t* getVertices(maslevtsov::point_t center, maslevtsov::point_t pnt2, maslevtsov::point_t pnt3)
  {
    double sqrLength1 = std::pow(center.x - pnt2.x, 2) + std::pow(center.y - pnt2.y, 2);
    double sqrLength2 = std::pow(pnt2.x - pnt3.x, 2) + std::pow(pnt2.y - pnt3.y, 2);
    double sqrLength3 = std::pow(center.x - pnt3.x, 2) + std::pow(center.y - pnt3.y, 2);
    double sqrHypotenuse = std::max(std::max(sqrLength1, sqrLength2), sqrLength3);
    double sqrSmallRadius = std::min(std::min(sqrLength1, sqrLength2), sqrLength3);
    std::size_t nVertices = M_PI / std::acos(std::sqrt(sqrSmallRadius / sqrHypotenuse));
    double bigRadius = std::sqrt(std::max(sqrLength1, sqrLength3));
    if (!isRightTriangle(center, pnt2, pnt3) || !isRightSize(nVertices, std::sqrt(sqrSmallRadius), bigRadius))
    {
      throw std::logic_error("incorrect regular input");
    }

    maslevtsov::point_t* vertices = new maslevtsov::point_t[nVertices];
    double angle = std::acos(std::sqrt(sqrSmallRadius / sqrHypotenuse));
    if (center.y == pnt3.y)
    {
      angle = 0;
    }
    for (std::size_t i = 0; i < nVertices; ++i)
    {
      double nextAngle = i * 2 * M_PI / nVertices + angle;
      vertices[i] = {center.x + bigRadius * std::cos(nextAngle), center.y + bigRadius * std::sin(nextAngle)};
    }

    return vertices;
  }
}

maslevtsov::Regular::Regular(point_t center, point_t pnt2, point_t pnt3):
  polygon(getNVertices(center, pnt2, pnt3), getVertices(center, pnt2, pnt3))
{}

double maslevtsov::Regular::getArea() const noexcept
{
  return polygon.getArea();
}

maslevtsov::rectangle_t maslevtsov::Regular::getFrameRect() const noexcept
{
  return polygon.getFrameRect();
}

void maslevtsov::Regular::move(point_t pnt) noexcept
{
  polygon.move(pnt);
}

void maslevtsov::Regular::move(double dx, double dy) noexcept
{
  polygon.move(dx, dy);
}

void maslevtsov::Regular::scale(double k)
{
  polygon.scale(k);
}

maslevtsov::Regular* maslevtsov::makeRegular(const double* arguments)
{
  Regular* reg = new Regular({arguments[0], arguments[1]}, {arguments[2], arguments[3]}, {arguments[4], arguments[5]});
  return reg;
}
