//
// ConvolutionFilter.h
// Created by Jonathon Meyer
//
#ifndef CON_FILTER_H
#define CON_FILTER_H

#include "ColorData.h"
#include "PixelBuffer.h"

class ConvolutionFilter
{
public:

	virtual void applyFilter(PixelBuffer *buf, float amount);
	//virtual ColorData modifyPixel(ColorData pixel)=0;
	virtual void applyKernel(int x,int y,PixelBuffer *buf,PixelBuffer *temp);

protected:
	float **kernel;
	int kernelSize;
	int midPoint;
};
#endif
