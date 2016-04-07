#ifndef BLURFILTER_H
#define BLURFILTER_H

//
// BlurFilter.h
// Created by Jacob Grafenstein
//

class ConvolutionFilter;

class BlurFilter : public ConvolutionFilter {
public:
  BlurFilter();
  ~BlurFilter();
  void adjustKernel(float amount);
  void applyFilter(PixelBuffer *buf, float amount);
private:

};

#endif
