#include <iostream>
#include <string>
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

  readFile.clear();
  readFile.seekg(0, std::ios::beg);

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
      Polygon shape(coordArr, coordSize);
      std::cout << "Area: " << shape.area() << std::endl;
      delete [] coordArr;
    }
  }

  readFile.close();
}
