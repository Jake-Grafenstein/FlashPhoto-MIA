//
// CalligraphyPen.cpp
// Created by Jonathon Meyer
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Tool.h"
#include "CalligraphyPen.h"

using namespace std;
using std::cerr;
using std::endl;
using std::fill;

CalligraphyPen::CalligraphyPen()
{
	int i,j;
	//allocate space for mask
	mask=(float**) malloc(7*sizeof(float*));
	for (i=0;i<7;i++)
	{
		mask[i]=(float*) malloc(7*sizeof(float));
	}
	//setup the mask
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if ((j<2) || (j>4))
			{
				mask[i][j]=0;
			}
			else
			{
				mask[i][j]=1;
			}
		}
	}

}

CalligraphyPen::~CalligraphyPen()
{
	int i;
	//deallocate mask
	for (i=0;i<7;i++)
	{
		free(mask[i]);
	}
	free(mask);
}

float** CalligraphyPen::computeMask()
{//is this supposed to be an accessor for mask?
	return mask;
}
