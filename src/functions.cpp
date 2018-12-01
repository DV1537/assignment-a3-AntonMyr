#include <iostream>
#include <string>
/**
 * Unsure if this library can be used, but I would argue that since it is a
 * string stream it's part of strings. It's necessary for my solution reading
 * the test files line by line and the only thing I'm using from it is the streaming
 * operator (>>).
 */
#include <sstream>

int numberOfBadChars (std::string &str) {
  std::size_t found = str.find_first_not_of("0123456789.- ");
  if (found!=std::string::npos)  {
    return found;
  }
  return 0;
}

void extractFloatsFromString(std::string &str, float *floatArr, int size) {
  std::stringstream ss;

  float tempFloat;
  std::string temp;

  ss << str;

  for(int i = 0; i < size; i++) {
    ss >> temp;
    if(std::stringstream(temp) >> tempFloat) {
      floatArr[i] = tempFloat;
    }
  }
}

int getFloatCount(std::string &str) {
  std::stringstream ss;

  float isFloat;
  int count = 0;
  std::string temp;

  ss << str;
  while(!ss.eof()) {
    ss >> temp;
    if(std::stringstream(temp) >> isFloat) {
      count++;
    }
  }
  return count;
}
