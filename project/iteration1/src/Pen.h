#ifndef PEN_H
#define PEN_H
//
// Pen.h
// Created by Jacob Grafenstein
//

class PixelBuffer;
class ColorData;
class Tool;

class Pen: public Tool
{
public:
  Pen();

  virtual ~Pen();

  float** computeMask();

};

#endif
