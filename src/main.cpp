#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "../include/Coordinate.hpp"
#include "../include/Polygon.hpp"
#include "../include/Functions.hpp"

int main(int argc, char* argv[]) {
  std::ifstream readFile;
  std::string c;
  int badChars;

  int size;
  int coordSize;
  int line = 0;

  float* floatsFromString;

  Coordinate *coordArr;

  Polygon *shapes;

  Coordinate *coordArrC = new Coordinate[4];
  coordArrC[0] = {1, 1};
  coordArrC[1] = {1, 2};
  coordArrC[2] = {1, 3};
  coordArrC[3] = {4, 1};


  if(argc == 1) {
    std::cout << "Need input file" << std::endl;
  }

  readFile.open(argv[1]);
  if(readFile.bad()) {
    std::cout << "Could not open file" << std::endl;
    exit(EXIT_FAILURE);
  }

  while(std::getline(readFile, c)) {
    badChars = numberOfBadChars(c);
    line++;
    if(badChars) {
      std::cout << "Cannot read file, bad character at line " << line << ", position: " << badChars << std::endl;
      exit(EXIT_FAILURE);
    }
    if(c.length() < 1) {
      std::cout << "Cannot read file, line " << line << " is empty" << badChars << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  if(line != 2) {
    std::cout << "Cannot read file, this program requires no more or less than 2 lines of coordinates" << std::endl;
    exit(EXIT_FAILURE);
  }

  readFile.clear();
  readFile.seekg(0, std::ios::beg);

  int currentLine = 0;
  shapes = new Polygon[line];
  while(std::getline(readFile, c)){
    size = getFloatCount(c);
    if(size % 2 == 0) {
      coordSize = size/2;
      floatsFromString = new float[size];
      coordArr = new Coordinate[coordSize];
      extractFloatsFromString(c, floatsFromString, size);
      int i = 0;
      while(i < coordSize) {
        for(int j = 0; j < size; j+=2) {
          coordArr[i] = {floatsFromString[j], floatsFromString[j+1]};
          i++;
        }
      }

      shapes[currentLine] = {coordArr, coordSize};
      delete [] coordArr;
      currentLine++;
    }
  }

  Polygon summed = shapes[0] + shapes[1];

  float area = summed.area();
  area = std::roundf(area * 1000) / 1000;

  std::cout << "Area: " << area << std::endl;

  readFile.close();
}
