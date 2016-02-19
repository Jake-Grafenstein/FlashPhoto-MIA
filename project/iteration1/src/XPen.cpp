//
// XPen.cpp
// Created by Jacob Grafenstein
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Tool.h"
#include "XPen.h"

using namespace std;
using std::cerr;
using std::endl;
using std::fill;

XPen::XPen()
{
    int i, j;
    maskSize = 7;
    //allocate space for mask, double array
  	mask=(float**) malloc(maskSize*sizeof(float*));
    for (i=0;i<maskSize;i++)
    {
      mask[i]=(float*) malloc(maskSize*sizeof(float));
    }

    for (i=0;i<maskSize;i++)
    {
      for (j=0;j<maskSize;j++)
      {
        if (i == j) {
          mask[i][j] = 1;
          switch (i) {
            case 1:
              mask[i][j+6] = 1;
	      break;
            case 2:
              mask[i][j+4] = 1;
	      break;
            case 3:
              mask[i][j+2] = 1;
	      break;
            case 4:
              break;
            case 5:
              mask[i][j-2] = 1;
	      break;
            case 6:
              mask[i][j-4] = 1;
	      break;
            case 7:
              mask[i][j-6] = 1;
              break;
            default:
              // do nothing
	      break;
          }
        }
        else {
          mask[i][j] = 0;
        }
      }
    }
}

XPen::~XPen()
{
  int i;
  for (i=0;i<maskSize;i++)
  {
      free(mask[i]);
  }
  free(mask);
}

float** XPen::computeMask()
{
  return mask;
}
