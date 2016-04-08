#ifndef MOTIONBLUR_H
#define MOTIONBLUR_H

//
// MotionBlur.h
// Created by Jacob Grafenstein
//

class ConvolutionFilter;

class MotionBlur : public ConvolutionFilter {
public:
  MotionBlur();
  ~MotionBlur();
  void applyFilter(PixelBuffer *buf, float amount, int direction);
  void adjustKernel(float amount, int direction);
private:


};

#endif