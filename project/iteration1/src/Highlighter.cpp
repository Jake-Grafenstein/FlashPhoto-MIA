//
// CalligraphyPen.cpp
// Created by Jonathon Meyer
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Tool.h"
#include "Highlighter.h"

using namespace std;
using std::cerr;
using std::endl;
using std::fill;

Highlighter::Highlighter()
{
	maskSize = 15;
	int i,j;
	//allocate space for mask
	mask=(float**) malloc(maskSize*sizeof(float*));
	for (i=0;i<maskSize;i++)
	{
		mask[i]=(float*) malloc(maskSize*sizeof(float));
	}
	//setup the mask
	for (i=0;i<maskSize;i++)
	{
		for (j=0;j<maskSize;j++)
		{
			if ((i<5) || (i>9))
			{
				mask[i][j]=0;
			}
			else
			{
				mask[i][j]=0.4;//only 40% highlighter color
			}
		}
	}

}

Highlighter::~Highlighter()
{
	int i;
	//deallocate mask
	for (i=0;i<maskSize;i++)
	{
		free(mask[i]);
	}
	free(mask);
}

float** Highlighter::computeMask()
{//is this supposed to be an accessor for mask?
	return mask;
}
