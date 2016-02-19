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
        if (i == j) {
          mask[i][j] = 1;
          switch (i) {
            case 1:
              mask[i][j+6] = 1;
            case 2:
              mask[i][j+4] = 1;
            case 3:
              mask[i][j+2] = 1;
            case 4:
              default;
            case 5:
              mask[i][j-2] = 1;
            case 6:
              mask[i][j-4] = 1;
            case 7:
              mask[i][j-6] = 1;
            default:
              // do nothing
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
  for (i=0;i<7;i++)
  {
      free(mask[i]);
  }
  free(mask);
}

float** XPen::ComputeMask()
{
  return mask;
}
