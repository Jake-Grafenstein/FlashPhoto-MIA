//
// XPen.h
// Created by Jacob Grafenstein
//

class PixelBuffer;
class ColorData;
class Tool;

class XPen: Tool
{
public:
  XPen();

  virtual ~XPen();

  float** computeMask();

};
