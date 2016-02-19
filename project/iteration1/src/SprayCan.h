// SprayCan.h
// Created by Stevie Frisbie

class PixelBuffer;
class ColorData;
class Tool;

class SprayCan: Tool
{

  public:
    SprayCan();
    virtual ~SprayCan();
    float** computeMask();
    float calculateDistance();
};
