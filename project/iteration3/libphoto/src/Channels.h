//
// Channels.h
// Created by Jonathon Meyer
//

#ifndef CHANNELS_H
#define CHANNELS_H

class Filter;

class Channels: public Filter {
public:
	Channels();
	~Channels();
	ColorData modifyPixel(ColorData pixel);
	void setR(float value);
	void setG(float value);
	void setB(float value);

private:
	float r,g,b;

};

#endif
