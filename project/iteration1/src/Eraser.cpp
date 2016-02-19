// Eraser.cpp
// Created by Stevie Frisbie

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include "Tool.h"
#include "Eraser.h"

using namespace std;
using std::cerr;
using std::endl;
using std::fill;

Eraser::Eraser()
{
	int i, j;
	maskSize = 21;
	//allocate space for mask
	mask = (float**) malloc(maskSize * sizeof(float*));
	for (i = 0; i < maskSize; i++)
	{
		mask[i] = (float*) malloc(maskSize * sizeof(float));
	}

	for (i = 0; i < maskSize; i++)
	{
		for (j = 0; j < maskSize; j++)
		{
			if (calculateDistance(i, j) <= 10.0)
			{
				mask[i][j] = 1;
			}
			else mask[i][j] = 0;
		}
	}
}

Eraser::~Eraser()
{
  int i;
  for (i = 0; i < maskSize; i++)
  {
      free(mask[i]);
  }
  free(mask);
}

float** Eraser::computeMask()
{
  return mask;
}

float Eraser::calculateDistance(int x, int y)
{
	return sqrt(pow(((float) x - 10.0), 2) + pow(((float) y - 10.0), 2));
}
