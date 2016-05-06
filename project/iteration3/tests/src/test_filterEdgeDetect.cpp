#include "FlashPhotoApp.h"

int main(int argc,char *argv[])
{
	FlashPhotoApp *prog = new FlashPhotoApp(argc, argv, 800,800,ColorData(1,1,0.95));
	prog->loadImageTest("TestImages/brainstack/mrbrain-8bit062.png");
  prog->gluiControl(FlashPhotoApp::UI_APPLY_EDGE);
  prog->setFileName("TestImages/brainstack_gold_edgedetect/mrbrain-8bit062.png");
	prog->gluiControl(FlashPhotoApp::UI_FILE_NAME);
	prog->gluiControl(FlashPhotoApp::UI_LOAD_STAMP_BUTTON);//saves canvas
  if (prog->compareBuffers())
	{
		printf("Testing: Blur\t SUCCESS\n");
	}
	else
	{
		printf("Testing: Blur\t FAIL\n");
	}
  return 0;
}
