//
// Pen.cpp
// Created by Jacob Grafenstein
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

Pen::Pen()
{
    int i, j;
    //allocate space for mask, double array
  	mask=(float**) malloc(7*sizeof(float*));
    for (i=0;i<7;i++)
    {
      mask[i]=(float*) malloc(7*sizeof(float));
    }

    for (i=0;i<7;i++)
    {
      for (j=0;j<7;j++)
      {
        if ((2 < i < 6) && (2 < j < 6)) {
          mask[i][j] = 1;
        }
        else {
          mask[i][j] = 0;
        }
      }
    }
}

Pen::~Pen()
{
  int i;
  for (i=0;i<7;i++)
  {
      free(mask[i]);
  }
  free(mask);
}

float** Pen::ComputeMask()
{
  return mask;
}
