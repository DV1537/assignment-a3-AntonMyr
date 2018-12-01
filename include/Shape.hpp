#ifndef SHAPE_H
#define SHAPE_H

#include "Coordinate.hpp"
#include <string>

class Shape {
 protected:
  Coordinate *coordsArr;
  int pointCount;
  std::string typeOfShape;
  Coordinate center;

 public:
  virtual std::string getType() = 0;
  float area();
  float circumference();
  virtual Coordinate position() = 0;
  bool isConvex();
  virtual float distance(Shape *s) = 0;
};

#endif
