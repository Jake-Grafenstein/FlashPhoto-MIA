//
// ConvolutionFilter.cpp
// created by Jonathon Meyer
//

#include <iostream>
#include <cstring>
#include "ConvolutionFilter.h"

//applies mask over whole canvas, should just need to define mask in subclasses
void ConvolutionFilter::applyFilter(PixelBuffer *buf)
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
			applyMask(i,j,buf, tempBuffer);
		}
	}
	PixelBuffer::copyPixelBuffer(tempBuffer,buf);
	delete tempBuffer;
}


//applies mask to one pixel, modifies temporary buffer
void ConvolutionFilter::applyMask(int x, int y,PixelBuffer *buf, PixelBuffer *temp)
{
	float r=0,g=0,b=0;
	int i,j;
	ColorData pixel;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			pixel = buf -> getPixel(x + i - (size/2),y + j - (size/2));
			r += (mask[i][j] * pixel.getRed());
			g += (mask[i][j] * pixel.getGreen());
			b += (mask[i][j] * pixel.getBlue());
		}
	}
	temp -> setPixel(x,y,ColorData(r,g,b));
}
