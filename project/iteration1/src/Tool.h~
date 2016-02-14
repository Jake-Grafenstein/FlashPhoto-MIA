//
// Tool.h
// Created by Jacob Grafenstein
//

#ifndef TOOL_H
#define TOOL_H

class PixelBuffer;
class ColorData;

class Tool {

 public:

  // This function will always be overwritten by the Tool subclass
  virtual float[][] computeMask() = 0;

  // Checks if the given tool is the active tool
  bool isActive();

  // Gets the background color of pixelBuffer
  ColorData getBackgroundColor(PixelBuffer);


 private:
  float **mask;
  float opacity;
  bool active;

};
