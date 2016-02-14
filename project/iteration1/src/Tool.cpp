//
// Tool.cpp
// Created by Jacob Grafenstein
//

#include <iostream>
#include <cstring>
#include "PixelBuffer.h"
#include "Tool.h"
#include "ColorData.h"

using std::cerr;
using std::endl;
using std::fill;

bool Tool::isActive() {
  return active;
}

ColorData Tool::getBackgroundColor(PixelBuffer) {
  return PixelBuffer::getBackgroundColor();
}
