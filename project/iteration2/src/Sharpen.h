#ifndef SHARPEN_H
#define SHARPEN_H

//
// Sharpen.h
// Created by Jacob Grafenstein
//

class ConvolutionFilter;

class Sharpen : public ConvolutionFilter {

public:
  Sharpen();
  ~Sharpen();
  void applyFilter(PixelBuffer *buf, float amount, int direction);

private:
  int midPoint;
};

#endif
