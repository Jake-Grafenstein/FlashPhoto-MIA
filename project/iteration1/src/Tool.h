//
// Tool.h
// Created by Jacob Grafenstein
//
#ifndef TOOL_H
#define TOOL_H

class Tool
{
public:

  // This function will always be overwritten by the Tool subclass
  virtual float** computeMask() = 0;

  // Checks if the given tool is the active tool
  bool isActive();
  int getMaskSize();

protected:
  float **mask;
  bool active;
  int maskSize;

};
#endif
