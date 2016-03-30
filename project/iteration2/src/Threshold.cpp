//
// Threshold.cpp
// Created by Jonathon Meyer
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Filter.h"
#include "Threshold.h"

using namespace std;

Threshold::Threshold()
{
	value = 0.5;
}

void Threshold::setValue(float value)
{
	this->value = value;
}

ColorData Threshold::modifyPixel(int x,int y,ColorData pixel)
{
	float r,g,b;
	r = pixel.getRed() > value;
	g = pixel.getGreen() > value;
	b = pixel.getBlue() > value;
	return ColorData(r,g,b);
}

// really just convention
Threshold::~Threshold() {}

