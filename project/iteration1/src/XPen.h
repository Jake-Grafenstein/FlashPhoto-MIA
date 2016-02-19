#ifndef X_PEN_H
#define X_PEN_H
//
// XPen.h
// Created by Jacob Grafenstein
//

class PixelBuffer;
class ColorData;
class Tool;

class XPen: public Tool
{
public:
  XPen();

  virtual ~XPen();

  float** computeMask();

};

#endif
