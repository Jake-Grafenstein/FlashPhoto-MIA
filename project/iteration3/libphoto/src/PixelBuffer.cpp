//
//  PixelBuffer.cpp
//  Originally created by the CSci-3081W TAs.
//

#include <iostream>
#include <cstring>
#include "PixelBuffer.h"
#include "ColorData.h"

using std::cerr;
using std::cout;
using std::endl;
using std::fill;

PixelBuffer::PixelBuffer(int w, int h, ColorData backgroundColor) : m_width(w), m_height(h) {
	m_backgroundColor = new ColorData(backgroundColor);
	m_pixels = new ColorData[w*h];
	fillPixelBufferWithColor(backgroundColor);
}

PixelBuffer::~PixelBuffer() {
	delete [] m_pixels;
	delete m_backgroundColor;
}

ColorData PixelBuffer::getPixel(int x, int y) const {
	ColorData pixelData;

	if ((x < 0) || (x >= m_width) || (y < 0) || (y >= m_height)) {
		cerr << "getPixel: x,y out of range: " << x << " " << y << endl;
	}
	else {
		int index = x + m_width*(y);
		pixelData = m_pixels[index];
	}
	return pixelData;
}

void PixelBuffer::setPixel(int x, int y, const ColorData& newPixel) {
	if ((x < 0) || (x >= m_width) || (y < 0) || (y >= m_height)) {
		cerr << "setPixel: x,y out of range: " << x << " " << y << endl;
	}
	else {
		int index = x + m_width*(y); //x + m_width*(m_height-(y+1));
		m_pixels[index] = newPixel;
	}
}

ColorData const * const PixelBuffer::getData() const {
	return m_pixels;
}

int PixelBuffer::getHeight() const {
	return m_height;
}

int PixelBuffer::getWidth() const {
	return m_width;
}

ColorData PixelBuffer::getBackgroundColor() {
	return *m_backgroundColor;
}

void PixelBuffer::fillPixelBufferWithColor(ColorData color) {
	fill(m_pixels, m_pixels+m_width*m_height, color);
}

void PixelBuffer::copyPixelBuffer(PixelBuffer * sourceBuffer, PixelBuffer * destinationBuffer) {
	if (destinationBuffer->getWidth() != sourceBuffer->getWidth() || destinationBuffer->getHeight() != sourceBuffer->getHeight()) {
		cerr << "copyPixelBuffer: " << "dimension mismatch" << endl;
		cout << "Temporary Buffer Width & Height: " << sourceBuffer->getWidth() << ", " << sourceBuffer->getHeight() << endl;
		cout << "Primary Buffer Width & Height: " << destinationBuffer->getWidth() << ", " << destinationBuffer->getHeight() << endl;
	}
	else {
		memcpy ( (void*)destinationBuffer->m_pixels, (void*) sourceBuffer->m_pixels, sizeof(ColorData)*destinationBuffer->m_height*destinationBuffer->m_width );
	}
}

bool PixelBuffer::compareBuffers(PixelBuffer * firstBuffer, PixelBuffer * secondBuffer) {
   int i, j;
   int w, h;
   w = firstBuffer->getWidth();
	 cout << "firstBuffer width: " << w << endl;
   h = firstBuffer->getHeight();
	 cout << "firstBuffer height: " << h << endl;

   for (i = 0; i < w; i++) {
       for (j = 0; j < h; j++) {
				 	ColorData firstPixel = firstBuffer->getPixel(i,j);
					ColorData secondPixel = secondBuffer->getPixel(i,j);
           if ((firstPixel.getRed() != secondPixel.getRed()) || (firstPixel.getGreen() != secondPixel.getGreen()) || (firstPixel.getBlue() != secondPixel.getBlue()) || (firstPixel.getAlpha() != secondPixel.getAlpha())) {
						 cout << "firstPixel.getRed(): " << firstPixel.getRed() << "! secondPixel.getRed(): " << secondPixel.getRed() << endl;
						 cout << "firstPixel.getGreen(): " << firstPixel.getGreen() << "! secondPixel.getGreen(): " << secondPixel.getGreen() << endl;
						 cout << "firstPixel.getBlue(): " << firstPixel.getBlue() << "! secondPixel.getBlue(): " << secondPixel.getBlue() << endl;
						 cout << "firstPixel.getAlpha(): " << firstPixel.getAlpha() << "! secondPixel.getAlpha(): " << secondPixel.getAlpha() << endl;
						 return false;
					 }
       }
   }
	 return true;
}
