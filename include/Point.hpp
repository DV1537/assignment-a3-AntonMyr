#ifndef POINT_H
#define POINT_H

#include "Shape.hpp"
#include <string>

class Point : public Shape {
  int pointCount = 1;
public:
  Point(Coordinate *coords) {
    coordsArr = new Coordinate[pointCount];
    coordsArr[0] = coords[0];

  };
  std::string getType() {
    return "Point";
  }
  float area() {
    return -1;
  };
  Coordinate position() {
    return coordsArr[0];
  }
  float distance(Shape *s) {
    float distance = coordsArr[0].distance(s->position());
    return distance;
  }
  ~Point() {
    delete [] coordsArr;
  }
};

#endif
