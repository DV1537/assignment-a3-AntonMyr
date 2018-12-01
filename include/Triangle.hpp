#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.hpp"

class Triangle : public Polygon {
public:
  Triangle(Coordinate *coords) : Polygon(coords, 3) {
    pointCount = 3;
    coordsArr = new Coordinate[pointCount];
    for(int i = 0; i < pointCount; i++) {
      coordsArr[i] = coords[i];
    }
  };

};

#endif
