//
// Pen.h
// Created by Jacob Grafenstein
//

class PixelBuffer;
class ColorData;
class Tool;

class Pen: Tool
{
public:
  Pen();

  virtual ~Pen();

  float** computeMask();

};
