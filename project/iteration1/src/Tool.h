//
// Tool.h
// Created by Jacob Grafenstein
//

class PixelBuffer;
class ColorData;

class Tool
{
public:

  // This function will always be overwritten by the Tool subclass
  virtual float** computeMask() = 0;

  // Checks if the given tool is the active tool
  bool isActive();

protected:
  float **mask;
  bool active;

};
