//
// ConvolutionFilter.cpp
// created by Jonathon Meyer
//

#include <iostream>
#include <cstring>
#include "ConvolutionFilter.h"


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
			tempPixel = modifyPixel(buf -> getPixel(i,j));
			tempBuffer -> setPixel(i,j,tempPixel);
		}
	}
	PixelBuffer::copyPixelBuffer(tempBuffer,buf);
	delete tempBuffer;
}


