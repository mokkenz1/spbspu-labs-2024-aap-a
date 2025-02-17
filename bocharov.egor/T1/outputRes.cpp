#include "outputRes.hpp"
#include <iomanip>
#include "getShapeInfo.hpp"

void bocharov::outputRes(std::ostream & output, Shape * const * myShape, size_t shapeSize)
{
  output << std::fixed << std::setprecision(1) << getAllArea(myShape, shapeSize);
  for (size_t i = 0; i < shapeSize; i++)
  {
    output << " " << myShape[i]->getFrameRect().pos.x - (myShape[i]->getFrameRect().width) / 2.0f;
    output << " " << myShape[i]->getFrameRect().pos.y - (myShape[i]->getFrameRect().height) / 2.0f;
    output << " " << myShape[i]->getFrameRect().pos.x + (myShape[i]->getFrameRect().width) / 2.0f;
    output << " " << myShape[i]->getFrameRect().pos.y + (myShape[i]->getFrameRect().height) / 2.0f;
  }
  output << '\n';
}
