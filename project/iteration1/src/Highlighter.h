//
// Highlighter.h
// Created by Jonathon Meyer
//

class PixelBuffer;
class ColorData;
class Tool;

class Highlighter: Tool
{
public:
  Highlighter();

  virtual ~Highlighter();
  // Instantiates abstract function from Tool
  float** computeMask();

};
