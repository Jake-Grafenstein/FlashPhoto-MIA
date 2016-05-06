#include "MIAApp.h"
#include "FlashPhotoApp.h"

int main(int argc,char *argv[])
{
	MIAApp *prog = new MIAApp(argc, argv, 800,800,ColorData(1,1,0.95));
	FlashPhotoApp *comp = new FlashPhotoApp(argc, argv, 800, 800, ColorData(1,1,0.95));
	prog->setTool(0);
	prog->mouseDragged(200,100);
	prog->setFileName("golds/mpen_testfile.png");
	prog->gluiControl(MIAApp::UI_FILE_NAME);
	prog->gluiControl(MIAApp::UI_SAVE_CANVAS_BUTTON);
	comp->setFileName("golds/mpen_gold.jpg");
	comp->gluiControl(FlashPhotoApp::UI_FILE_NAME);
	comp->gluiControl(FlashPhotoApp::UI_LOAD_CANVAS_BUTTON);
	comp->setFileName("golds/mpen_testfile.png");
	comp->gluiControl(FlashPhotoApp::UI_FILE_NAME);
	comp->gluiControl(FlashPhotoApp::UI_LOAD_STAMP_BUTTON);
	if (comp->compareBuffers())
	{
		printf("Testing: MPen\t\t SUCCESS\n");
	}
	else
	{
		printf("Testing: MPen\t\t FAIL\n");
	}
	return 0;
}
