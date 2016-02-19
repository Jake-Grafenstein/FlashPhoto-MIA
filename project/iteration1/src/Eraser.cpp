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
	//allocate space for mask
	mask = (float**) malloc(21 * sizeof(float*));
	for (i = 0; i < 21; i++)
	{
		mask[i] = (float*) malloc(21 * sizeof(float));
	}
	
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 21; j++)
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
  for (i = 0; i < 21; i++)
  {
      free(mask[i]);
  }
  free(mask);
}

float** Eraser::ComputeMask()
{
  return mask;
}

float calculateDistance(int x, int y)
{
	return sqrt(((float) x - 10.0)^2 + ((float) y - 10.0)^2);
}
 
