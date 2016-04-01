//
// ConvolutionFilter.h
// Created by Jacob Grafenstein
//

#ifndef CONVOLUTIONFILTER_H
#define CONVOLUTIONFILTER_H

#include "Filter.h"
#include "PixelBuffer.h"
#include "ColorData.h"

class ConvolutionFilter : public Filter {
public:
  virtual void applyKernelToBuffer();
  virtual void setKernelValues(int kernelSize);

private:
  float** kernel;

};

#endif 
