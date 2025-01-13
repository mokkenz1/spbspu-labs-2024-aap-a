#include "ring.hpp"
#include <cmath>
#include <stdexcept>

sveshnikov::Ring::Ring(point_t center, double long_radius, double short_radius):
  small_ellipse_(center, short_radius, short_radius),
  big_ellipse_(center, long_radius, long_radius)
{
  if (!(long_radius > short_radius && short_radius > 0))
  {
    throw std::logic_error("ERROR: incorrect radius values of ring");
  }
}

double sveshnikov::Ring::getArea() const
{
  return big_ellipse_.getArea() - small_ellipse_.getArea();
}

sveshnikov::rectangle_t sveshnikov::Ring::getFrameRect() const
{
  return big_ellipse_.getFrameRect();
}

void sveshnikov::Ring::move(const point_t p)
{
  small_ellipse_.move(p);
  big_ellipse_.move(p);
}

void sveshnikov::Ring::move(double dx, double dy)
{
  small_ellipse_.move(dx, dy);
  big_ellipse_.move(dx, dy);
}

void sveshnikov::Ring::unsafe_scale(double k)
{
  small_ellipse_.scale(k);
  big_ellipse_.scale(k);
}
