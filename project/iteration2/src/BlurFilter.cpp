//
// BlurFilter.cpp
// Created by Jacob Grafenstein
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include "ConvolutionFilter.h"
#include "BlurFilter.h"

using namespace std;

BlurFilter::BlurFilter() {
  int i;
  kernelSize = 3;

  kernel = (float **) malloc(kernelSize*sizeof(float *));
  for (i = 0; i < kernelSize; i++) {
    kernel[i] = (float *) malloc(kernelSize*sizeof(float));
  }
}

BlurFilter::~BlurFilter() {
  int i;

  for (i = 0; i < kernelSize; i++) {
    free(kernel[i]);
  }
  free(kernel);
}

void BlurFilter::adjustKernel(float amount) {
  int i, j;
  float blurRatio = 1.0 / amount;

  for (i = 0; i < kernelSize; i++) {
    for (j = 0; j < kernelSize; j++) {
      if (((i == 0) || (i== kernelSize-1)) && ((j == 0) || (j == kernelSize-1))) {
        kernel[i][j] = 0.0;
      } else {
        kernel[i][j] = blurRatio;
      }
    }
  }
}

void BlurFilter::applyFilter(PixelBuffer *buf, float amount) {
  adjustKernel(amount);
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
