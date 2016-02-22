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

/*Tool::Tool() {
  //we won't need this unless it does something, right now it just causes an error
}*/

bool Tool::isActive() {
  return active;
}

int Tool::getMaskSize() {
  return maskSize;
}

int Tool::getPixel(int x,int y)
{
	if (x>=0 && y>=0 && x<maskSize && y<maskSize)
	{
		return mask[x][y];
	}
	else
	{
		return -1;
	}
}
