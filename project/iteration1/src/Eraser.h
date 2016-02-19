// Eraser.h
// Created by Stevie Frisbie

class PixelBuffer;
class ColorData;
class Tool;

class Eraser: Tool
{

  public:
    Eraser();
    virtual ~Eraser();
    float** computeMask();
    float calculateDistance();
};
