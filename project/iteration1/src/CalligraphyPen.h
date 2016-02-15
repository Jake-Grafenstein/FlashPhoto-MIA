//
// CalligraphyPen.h
// Created by Jonathon Meyer
//

class PixelBuffer;
class ColorData;
class Tool;

class CalligraphyPen: Tool
{
public:
  CalligraphyPen();

  virtual ~CalligraphyPen();
  // Instantiates abstract function from Tool
  float** computeMask();

};
