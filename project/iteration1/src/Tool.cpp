//
// Tool.cpp
// Created by Jacob Grafenstein
//

#include <iostream>
#include <cstring>
#include "Tool.h"

using std::cerr;
using std::endl;
using std::fill;

Tool::Tool() {
  
}

bool Tool::isActive() {
  return active;
}
