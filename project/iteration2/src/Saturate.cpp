//
// Saturate.cpp
// Created by Jonathon Meyer
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Filter.h"
#include "Saturate.h"

using namespace std;

Saturate::Saturate()
{
	value = 1.0;
}

void Saturate::setValue(float value)
{
	this->value = value;
}

ColorData Saturate::modifyPixel(ColorData pixel)
{
	float r,g,b;
	if (value > 0)
	{
		r = pixel.getRed() * value;
		g = pixel.getGreen() * value;
		b = pixel.getBlue() * value;
	}
	else
	{
		r = 1 - pixel.getRed() * value;
                g = 1 - pixel.getGreen() * value;
                b = 1 - pixel.getBlue() * value;
	}
	return ColorData(r,g,b);
}

// really just convention
Saturate::~Saturate() {}

