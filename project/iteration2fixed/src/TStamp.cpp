//
//  TStamp.cpp
//  PhotoShop Proj
//
//  Created by Seth Johnson on 4/4/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include "TStamp.h"
#include "PixelBuffer.h"
#include "ColorData.h"

PixelBuffer *TStamp::m_stampBuffer = NULL;

TStamp::TStamp()
{
    // default buffer
    mask = NULL;
//    m_maxSmear = 0;
}

TStamp::~TStamp()
{
    delete m_stampBuffer;
}

int TStamp::getWidth()
{
    return TStamp::m_stampBuffer->getWidth();
}

int TStamp::getHeight()
{
    return TStamp::m_stampBuffer->getHeight();
}

void TStamp::setStampBuffer(PixelBuffer * stampBuffer)
{
    if (m_stampBuffer) {
        delete m_stampBuffer;
    }
    m_stampBuffer = stampBuffer;
    maskSize = m_stampBuffer->getWidth();
}

/*std::string TStamp::getName() {
    return "Stamp";
}*/

void TStamp::paintMask(int x,int y,PixelBuffer **displayBuffer,ColorData color,ColorData backgroundColor)
{
	int i,j,bufferI,bufferJ,width,height;
	width = (*displayBuffer)->getWidth();
	height = (*displayBuffer)->getHeight();
	for (i=0;i<maskSize;i++)
	{
		for (j=0;j<maskSize;j++)
		{
			bufferI = x + i - (maskSize/2) - 1;
			bufferJ = y + j - (maskSize/2) - 1;
			if ((bufferI > 0) && (bufferI < width) && (bufferJ > 0) && (bufferJ < height))
			{
				(**displayBuffer).setPixel(bufferI,height - bufferJ,m_stampBuffer->getPixel(i,j));
			}
		}
	}
}

/*ColorData TStamp::processPixel(int maskX, int maskY, ColorData toolColor, PixelBuffer* buffer, int bufferX, int bufferY)
{
    ColorData stampColor = TStamp::m_stampBuffer->getPixel(maskX, maskY);
    
    stampColor.setRed(toolColor.getRed() * stampColor.getRed());
    stampColor.setGreen(toolColor.getGreen() * stampColor.getGreen());
    stampColor.setBlue(toolColor.getBlue() * stampColor.getBlue());
    
    float alpha = stampColor.getAlpha();
    
    return stampColor*alpha + buffer->getPixel(bufferX, bufferY)*(1-alpha);
}
*/
