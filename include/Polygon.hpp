#ifndef POLYGON_H
#define POLYGON_H

#include <string>
#include "Shape.hpp"

class Polygon : public Shape {
private:
  bool convex;
  bool regular = true;
  bool convexHasBeenRun = false;
  bool positionHasBeenRun = false;

public:
  Polygon(Coordinate *coords, int coordsSize);
  std::string getType();
  float area();
  float circumference();
  Coordinate position();
  bool isConvex();
  float distance(Shape *s);
  ~Polygon();

};

#endif
