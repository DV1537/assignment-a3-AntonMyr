#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
 private:
  float xVal;
  float yVal;

 public:
  Coordinate(float x, float y);
  Coordinate();
  float getX();
  float getY();
  float distance(Coordinate d);
};

#endif
