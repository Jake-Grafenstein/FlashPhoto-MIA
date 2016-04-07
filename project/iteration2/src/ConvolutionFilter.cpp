//
// ConvolutionFilter.cpp
// created by Jonathon Meyer
//

#include <iostream>
#include <cstring>
#include "ConvolutionFilter.h"

//applies kernel over whole canvas, should just need to define kernel in subclasses
void ConvolutionFilter::applyFilter(PixelBuffer *buf, float amount, int direction)
{
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


//applies kernel to one pixel, modifies temporary buffer
void ConvolutionFilter::applyKernel(int x, int y,PixelBuffer *buf, PixelBuffer *temp)
{
	float r=0,g=0,b=0;
	int i,j;
	ColorData pixel;
	for (i = 0; i < kernelSize; i++)
	{
		for (j = 0; j < kernelSize; j++)
		{
			pixel = buf -> getPixel(x + i - (kernelSize/2),y + j - (kernelSize/2));
			r += (kernel[i][j] * pixel.getRed());
			g += (kernel[i][j] * pixel.getGreen());
			b += (kernel[i][j] * pixel.getBlue());
		}
	}
	temp -> setPixel(x,y,ColorData(r,g,b));
}
