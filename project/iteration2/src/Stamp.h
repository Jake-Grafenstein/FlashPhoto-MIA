#ifndef STAMP_H
#define STAMP_H
// SprayCan.h
// Created by Stevie Frisbie

class PixelBuffer;
class ColorData;
class Tool;

class Stamp: public Tool
{

  public:
    Stamp();
    virtual ~Stamp();
    void updateStamp(PixelBuffer* newStamp);

  private:
    PixelBuffer* stampBuffer;
};

#endif
