//
// MotionBlur.cpp
// Created by Jacob Grafenstein
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include "ConvolutionFilter.h"
#include "MotionBlur.h"

using namespace std;

MotionBlur::MotionBlur() {
  int i, j;
  kernelSize = 9;
  midPoint = floor(kernelSize/2);

  kernel = (float **) malloc(kernelSize*sizeof(float *));
  for (i = 0; i < kernelSize; i++) {
    kernel[i] = (float *) malloc(kernelSize*sizeof(float));
  }

  for (i = 0; i < kernelSize; i++) {
    for (j = 0; j < kernelSize; j++) {
      kernel[i][j] = 0.0;
    }
  }

}

MotionBlur::~MotionBlur() {
  int i;

  for (i = 0; i < kernelSize; i++) {
    free(kernel[i]);
  }
  free(kernel);
}

void MotionBlur::adjustKernel(float amount, int direction) {
  int i, j;
  float blurRatio = 1.0 / amount;
  if (direction == 0) {
    for (i = 0; i < kernelSize; i++) {
      kernel[midPoint][i] = amount;
    }
  } else if (direction == 1) {
    for (i = 0; i < kernelSize; i++) {
      kernel[i][midPoint] = amount;
    }
  } else if (direction == 2) {
    for (i = 0; i < kernelSize; i++) {
      for (j = 0; j < kernelSize; j++) {
        if (i == j) {
          kernel[i][j] = amount;
        }
      }
    }
  } else if (direction == 3) {
    for (i = 0; i < kernelSize; i++) {
      for (j = 0; j < kernelSize; j++) {
        if ((kernelSize - 1 - j) == i) {
          kernel[i][j] = amount;
        }
      }
    }
  }
}

void MotionBlur::applyFilter(PixelBuffer *buf, float amount, int direction) {
  adjustKernel(amount, direction);
	int i,j,width,height;
	ColorData tempPixel;
	PixelBuffer *tempBuffer;
	width = buf -> getWidth();
	height = buf -> getHeight();
	tempBuffer = new PixelBuffer(width,height,ColorData(0,0,0));
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{
			applyKernel(i,j,buf,tempBuffer);
		}
	}
	PixelBuffer::copyPixelBuffer(tempBuffer,buf);
	delete tempBuffer;
}
