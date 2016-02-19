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
			if (calculateDistance(i, j) >= 20.0)
			{
				mask[i][j] = 0;
			}
			else if (calculateDistance(i, j) >= 19.0)
			{
				mask[i][j] = 0.01;
			}
			else if (calculateDistance(i, j) >= 18.0)
			{
				mask[i][j] = 0.02;
			}
			else if (calculateDistance(i, j) >= 17.0)
			{
				mask[i][j] = 0.03;
			}
			else if (calculateDistance(i, j) >= 16.0)
			{
				mask[i][j] = 0.04;
			}
			else if (calculateDistance(i, j) >= 15.0)
			{
				mask[i][j] = 0.05;
			}
			else if (calculateDistance(i, j) >= 14.0)
			{
				mask[i][j] = 0.06;
			}
			else if (calculateDistance(i, j) >= 13.0)
			{
				mask[i][j] = 0.07;
			}
			else if (calculateDistance(i, j) >= 12.0)
			{
				mask[i][j] = 0.08;
			}
			else if (calculateDistance(i, j) >= 11.0)
			{
				mask[i][j] = 0.09;
			}
			else if (calculateDistance(i, j) >= 10.0)
			{
				mask[i][j] = 0.10;
			}
			else if (calculateDistance(i, j) >= 9.0)
			{
				mask[i][j] = 0.11;
			}
			else if (calculateDistance(i, j) >= 8.0)
			{
				mask[i][j] = 0.12;
			}
			else if (calculateDistance(i, j) >= 7.0)
			{
				mask[i][j] = 0.13;
			}
			else if (calculateDistance(i, j) >= 6.0)
			{
				mask[i][j] = 0.14;
			}
			else if (calculateDistance(i, j) >= 5.0)
			{
				mask[i][j] = 0.15;
			}
			else if (calculateDistance(i, j) >= 4.0)
			{
				mask[i][j] = 0.16;
			}
			else if (calculateDistance(i, j) >= 3.0)
			{
				mask[i][j] = 0.17;
			}
			else if (calculateDistance(i, j) >= 2.0)
			{
				mask[i][j] = 0.18;
			}
			else if (calculateDistance(i, j) >= 1.0)
			{
				mask[i][j] = 0.19;
			}
			else if (calculateDistance(i, j) >= 0.0)
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

float calculateDistance(int x, int y)
{
	return sqrt(((float) x - 20.0)^2 + ((float) y - 20.0)^2);
}
