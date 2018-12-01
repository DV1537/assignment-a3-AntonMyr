#include <iostream>
#include <cmath>
#include "../include/Coordinate.hpp"

Coordinate::Coordinate(float x, float y) : xVal(x), yVal(y){};
Coordinate::Coordinate(){};

float Coordinate::getX() {
  return xVal;
};

float Coordinate::getY() {
  return yVal;
};

float Coordinate::distance(Coordinate d) {
  float dx = d.getX() - xVal;
  float dy = d.getY() - yVal;
  float distance = std::hypot(dx, dy);
  return distance;
};
