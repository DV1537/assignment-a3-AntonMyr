#ifndef LINE_H
#define LINE_H

#include "Shape.hpp"
#include <string>
#include <cmath>

class Line : public Shape {
  int pointCount = 2;
public:
  Line(Coordinate *coords) {
    coordsArr = new Coordinate[pointCount];
    for(int i = 0; i < pointCount; i++) {
      coordsArr[i] = coords[i];
    }
  };
  std::string getType() {
    return "Line";
  };
  float area(){
    return -1;
  };
  Coordinate position() {
    float xMax = fmax(coordsArr[1].getX(), coordsArr[0].getX());
    float xMin = xMax == coordsArr[1].getX() ? coordsArr[0].getX() : coordsArr[1].getX();
    float yMax = fmax(coordsArr[1].getY(), coordsArr[0].getY());
    float yMin = xMax == coordsArr[1].getY() ? coordsArr[0].getY() : coordsArr[1].getY();

    float dx = xMax - abs(xMin);
    float dy = yMax - abs(yMin);
    Coordinate center = {dx, dy};
    return center;
    //
  };
  ~Line() {
    delete [] coordsArr;
  }
};

#endif
