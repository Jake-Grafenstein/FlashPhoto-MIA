// SprayCan.cpp
// Created by Stevie Frisbie

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include "Tool.h"
#include "SprayCan.h"

using namespace std;
using std::cerr;
using std::endl;
using std::fill;

SprayCan::SprayCan()
{
	int i, j;
	//allocate space for mask
	mask = (float**) malloc(41 * sizeof(float*));
	for (i = 0; i < 41; i++)
	{
		mask[i] = (float*) malloc(41 * sizeof(float));
	}

	for (i = 0; i < 41; i++)
	{
		for (j = 0; j < 41; j++)
		{
			float distance = calculateDistance(i, j)
			if (distance >= 20.0)
			{
				mask[i][j] = 0;
			}
			else if (distance >= 19.0)
			{
				mask[i][j] = 0.01;
			}
			else if (distance >= 18.0)
			{
				mask[i][j] = 0.02;
			}
			else if (distance >= 17.0)
			{
				mask[i][j] = 0.03;
			}
			else if (distance >= 16.0)
			{
				mask[i][j] = 0.04;
			}
			else if (distance >= 15.0)
			{
				mask[i][j] = 0.05;
			}
			else if (distance >= 14.0)
			{
				mask[i][j] = 0.06;
			}
			else if (distance >= 13.0)
			{
				mask[i][j] = 0.07;
			}
			else if (distance >= 12.0)
			{
				mask[i][j] = 0.08;
			}
			else if (distance >= 11.0)
			{
				mask[i][j] = 0.09;
			}
			else if (distance >= 10.0)
			{
				mask[i][j] = 0.10;
			}
			else if (distance >= 9.0)
			{
				mask[i][j] = 0.11;
			}
			else if (distance >= 8.0)
			{
				mask[i][j] = 0.12;
			}
			else if (distance >= 7.0)
			{
				mask[i][j] = 0.13;
			}
			else if (distance >= 6.0)
			{
				mask[i][j] = 0.14;
			}
			else if (distance >= 5.0)
			{
				mask[i][j] = 0.15;
			}
			else if (distance >= 4.0)
			{
				mask[i][j] = 0.16;
			}
			else if (distance >= 3.0)
			{
				mask[i][j] = 0.17;
			}
			else if (distance >= 2.0)
			{
				mask[i][j] = 0.18;
			}
			else if (distance >= 1.0)
			{
				mask[i][j] = 0.19;
			}
			else if (distance >= 0.0)
			{
				mask[i][j] = 0.20;
			}
		}
	}
}

SprayCan::~SprayCan()
{
  int i;
  for (i=0;i<41;i++)
  {
      free(mask[i]);
  }
  free(mask);
}

float** SprayCan::ComputeMask()
{
  return mask;
}

float SprayCan::calculateDistance(int x, int y)
{
	return sqrt(((float) x - 20.0)^2 + ((float) y - 20.0)^2);
}
