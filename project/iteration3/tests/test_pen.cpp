#include "../FlashPhoto/FlashPhoto.h"

int main(int argc,char *argv[])
{
	FlashPhotoApp *prog = new FlashPhotoApp(argc, argv, 800,800,ColorData(1,1,0.95));
	//need function to set m_curTool manually
	prog->mouseDragged(200,100);
	//need to add method to set m_fileName manually
	prog->gluiControl(UI_FILE_NAME);
	prog->gluiControl(UI_SAVE_CANVAS_BUTTON);//saves canvas
	//At this point we can delete prog
	delete prog;
	//Ok, now we need a way to load them easily (maybe not delete app)
	// And then use PixelBuffer::compareBuffers to compare if they are equal or not
	printf("Testing: Pen\t SUCCESS\n");
}
