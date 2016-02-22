//
//  BrushWorkApp.cpp
//  Originally created by the CSci-3081W TAs.
//

#include "BrushWorkApp.h"
#include "ColorData.h"
#include "PixelBuffer.h"
#include "CalligraphyPen.h"
#include "Highlighter.h"
#include "Eraser.h"
#include "SprayCan.h"
#include "Pen.h"
#include "XPen.h"
#include "Tool.h"
#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

BrushWorkApp::BrushWorkApp(int argc, char* argv[], int width, int height, ColorData backgroundColor) :
	BaseGfxApp(argc, argv, width, height, 50, 50, GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH, true, width+51, 50) {
	m_curTool = 0;//we'll just set this to the first one on initialization
	// Set the name of the window
	setCaption("BrushWork");
	initializeTools();


	// Initialize Interface
	initializeBuffers(backgroundColor, width, height);

	initGlui();
	initGraphics();
}

void BrushWorkApp::display() {
	// TODO: Update the contents of the display buffer
	drawPixels(0, 0, m_width, m_height, m_displayBuffer->getData());
}

void paintMask(int x,int y)
{
	int i,j,bufferI,bufferJ;
	float red,green,blue;
	int maskSize = tools[m_curTool].getMaskSize();
	if (m_curTool == 1)
	{//eraser
		red = backgroundColor.getRed();
		green = backgroundColor.getGreen();
		blue = backgroundColor.getBlue();
	}
	else
	{//everything else
		red = m_curColorRed;
		green = m_curColorGreen;
		blue = m_curColorBlue;
	}
	//i,j will be positions in the mask
	for (i=0;i<maskSize;i++)
	{
		for (j=0;j<maskSize;j++)
		{
			bufferI = i - (maskSize/2) - 1;
			bufferJ = j - (maskSize/2) - 1;
			if ((bufferI > 0) && (bufferI < width) && (bufferJ > 0) && (bufferJ < height))
			{//make sure width and length are right, be prepared to swap if necessary
				m_displayBuffer[bufferI*maskSize + bufferJ] *= 1 - tools[m_curTool].getPixel(i,j);
				m_displayBuffer[bufferI*maskSize + bufferJ] += (new ColorData(red,green,blue))*tools[m_curTool].getPixel(i,j);
				//not sure if above line is right way to create ColorData object, need verification
			}
		}
	}
}



BrushWorkApp::~BrushWorkApp() {
	if (m_displayBuffer) {
		delete m_displayBuffer;
	}
}


void BrushWorkApp::mouseDragged(int x, int y) {

}

void BrushWorkApp::mouseMoved(int x, int y) {

}


void BrushWorkApp::leftMouseDown(int x, int y) {
	std::cout << "mousePressed " << x << " " << y << std::endl;
}

void BrushWorkApp::leftMouseUp(int x, int y) {
	std::cout << "mouseReleased " << x << " " << y << std::endl;
}

void BrushWorkApp::initializeBuffers(ColorData backgroundColor, int width, int height) {
	m_displayBuffer = new PixelBuffer(width, height, backgroundColor);
}

void BrushWorkApp::initializeTools() {
	tools.push_back(new Pen());
	tools.push_back(new Eraser());
	tools.push_back(new SprayCan());
	tools.push_back(new CalligraphyPen());
	tools.push_back(new Highlighter());
	tools.push_back(new XPen());
}

void BrushWorkApp::initGlui() {
	// Select first tool (this activates the first radio button in glui)
	m_curTool = 0;

	GLUI_Panel *toolPanel = new GLUI_Panel(m_glui, "Tool Type");
	GLUI_RadioGroup *radio = new GLUI_RadioGroup(toolPanel, &m_curTool, UI_TOOLTYPE, s_gluicallback);

	// Create interface buttons for different tools:
	new GLUI_RadioButton(radio, "Pen");
	new GLUI_RadioButton(radio, "Eraser");
	new GLUI_RadioButton(radio, "Spray Can");
	new GLUI_RadioButton(radio, "Caligraphy Pen");
	new GLUI_RadioButton(radio, "Highlighter");

	GLUI_Panel *colPanel = new GLUI_Panel(m_glui, "Tool Color");

	m_curColorRed = 0;
	m_spinnerR  = new GLUI_Spinner(colPanel, "Red:", &m_curColorRed, UI_COLOR_R, s_gluicallback);
	m_spinnerR->set_float_limits(0, 1.0);

	m_curColorGreen = 0;
	m_spinnerG  = new GLUI_Spinner(colPanel, "Green:", &m_curColorGreen, UI_COLOR_G, s_gluicallback);
	m_spinnerG->set_float_limits(0, 1.0);

	m_curColorBlue = 0;
	m_spinnerB  = new GLUI_Spinner(colPanel, "Blue:", &m_curColorBlue, UI_COLOR_B, s_gluicallback);
	m_spinnerB->set_float_limits(0, 1.0);
	new GLUI_Button(colPanel, "Red", UI_PRESET_RED, s_gluicallback);
	new GLUI_Button(colPanel, "Orange", UI_PRESET_ORANGE, s_gluicallback);
	new GLUI_Button(colPanel, "Yellow", UI_PRESET_YELLOW, s_gluicallback);
	new GLUI_Button(colPanel, "Green", UI_PRESET_GREEN, s_gluicallback);
	new GLUI_Button(colPanel, "Blue", UI_PRESET_BLUE, s_gluicallback);
	new GLUI_Button(colPanel, "Purple", UI_PRESET_PURPLE, s_gluicallback);
	new GLUI_Button(colPanel, "White", UI_PRESET_WHITE, s_gluicallback);
	new GLUI_Button(colPanel, "Black", UI_PRESET_BLACK, s_gluicallback);


	new GLUI_Button(m_glui, "Quit", UI_QUIT, (GLUI_Update_CB)exit);
}


void BrushWorkApp::initGraphics() {
	// Initialize OpenGL for 2D graphics as used in the BrushWork app
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0, m_width, 0, m_height);
	glViewport(0, 0, m_width, m_height);
}



void BrushWorkApp::gluiControl(int controlID) {
	switch (controlID) {
		case UI_PRESET_RED:
			m_curColorRed = 1;
			m_curColorGreen = 0;
			m_curColorBlue = 0;
			break;
		case UI_PRESET_ORANGE:
			m_curColorRed = 1;
			m_curColorGreen = 0.5;
			m_curColorBlue = 0;
			break;
		case UI_PRESET_YELLOW:
			m_curColorRed = 1;
			m_curColorGreen = 1;
			m_curColorBlue = 0;
			break;
		case UI_PRESET_GREEN:
			m_curColorRed = 0;
			m_curColorGreen = 1;
			m_curColorBlue = 0;
			break;
		case UI_PRESET_BLUE:
			m_curColorRed = 0;
			m_curColorGreen = 0;
			m_curColorBlue = 1;
			break;
		case UI_PRESET_PURPLE:
			m_curColorRed = 0.5;
			m_curColorGreen = 0;
			m_curColorBlue = 1;
			break;
		case UI_PRESET_WHITE:
			m_curColorRed = 1;
			m_curColorGreen = 1;
			m_curColorBlue = 1;
			break;
		case UI_PRESET_BLACK:
			m_curColorRed = 0;
			m_curColorGreen = 0;
			m_curColorBlue = 0;
			break;
		default:
			break;
	}

	m_spinnerB->set_float_val(m_curColorBlue);
	m_spinnerG->set_float_val(m_curColorGreen);
	m_spinnerR->set_float_val(m_curColorRed);
}
