//
// Sharpen.cpp
// Created by Jacob Grafenstein
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include "ConvolutionFilter.h"
#include "Sharpen.h"

Sharpen::Sharpen() {
  kernelSize = 3;
  kernel = (float **) malloc(kernelSize * sizeof(float *));
  for (int i = 0; i < kernelSize; i++) {
    kernel[i] = (float *) malloc(kernelSize + sizeof(float));
  }

  midPoint = floor(kernelSize/2);

  kernel[midPoint][midPoint] = 9.0;
  for (int j = 0; j < kernelSize; j++) {
    for (int k = 0; k < kernelSize; k++) {
      if ((j == k) == midPoint) {
        // Do Nothing
      } else {
        kernel[j][k] = -1.0;
      }
    }
  }
}

Sharpen::~Sharpen() {
  for (int i = 0; i < kernelSize; i++) {
    free(kernel[i]);
  }
  free(kernel);
}

void Sharpen::applyFilter(PixelBuffer *buf, float amount)
{
  kernel[midPoint][midPoint] = amount;
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
			applyKernel(i,j,buf, tempBuffer);
		}
	}
	PixelBuffer::copyPixelBuffer(tempBuffer,buf);
	delete tempBuffer;
}
