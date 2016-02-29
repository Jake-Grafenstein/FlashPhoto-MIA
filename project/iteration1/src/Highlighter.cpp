//
// Highlighter.cpp
// Created by Jonathon Meyer
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Tool.h"
#include "Highlighter.h"

using namespace std;
using std::cerr;
using std::endl;
using std::fill;

Highlighter::Highlighter()
{
	maskSize = 15;
	int i,j;
	//allocate space for mask
	mask=(float**) malloc(maskSize*sizeof(float*));
	for (i=0;i<maskSize;i++)
	{
		mask[i]=(float*) malloc(maskSize*sizeof(float));
	}
	//setup the mask
	for (i=0;i<maskSize;i++)
	{
		for (j=0;j<maskSize;j++)
		{
			if ((i<5) || (i>9))
			{
				mask[i][j]=0;
			}
			else
			{
				mask[i][j]=0.4;//only 40% highlighter color
			}
		}
	}

}

Highlighter::~Highlighter()
{
	int i;
	//deallocate mask
	for (i=0;i<maskSize;i++)
	{
		free(mask[i]);
	}
	free(mask);
}

void Highlighter::paintMask(int x,int y,PixelBuffer **displayBuffer,ColorData color,ColorData backgroundColor)
{//overwritten to allow for dark colors to show through
        int i,j,bufferI,bufferJ,width,height;
	float r,g,b,newR,newG,newB;
        width = (*displayBuffer)->getWidth();
        height = (*displayBuffer)->getHeight();
        ColorData tempPixel;
        for (i=0;i<maskSize;i++)
        {
                for (j=0;j<maskSize;j++)
                {
                        bufferI = x + i - (maskSize/2) - 1;
                        bufferJ = y + j - (maskSize/2) - 1;
                        if ((bufferI > 0) && (bufferI < width) && (bufferJ > 0) && (bufferJ < height))
                        {//make sure width and length are right, be prepared to swap if necessary
                                tempPixel = (**displayBuffer).getPixel(bufferI,height - bufferJ);
				r = tempPixel.getRed();
				g = tempPixel.getGreen();
				b = tempPixel.getBlue();
				tempPixel = tempPixel * (1 - getPixel(i,j));
				tempPixel = tempPixel + (color * getPixel(i,j));
				newR = tempPixel.getRed();
				newG = tempPixel.getGreen();
				newB = tempPixel.getBlue();
				if (r < newR)
				{ newR = r; }
				if (g < newG)
				{ newG = g; }
				if (b < newB)
				{ newB = b; }
				tempPixel.setRed(newR);
				tempPixel.setGreen(newG);
				tempPixel.setBlue(newB);
                                (**displayBuffer).setPixel(bufferI,height - bufferJ,tempPixel);
                        }
                }
        }
}

