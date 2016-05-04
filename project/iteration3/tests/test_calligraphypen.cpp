#include "../FlashPhoto/FlashPhoto.h"

int main(int argc,char *argv[])
{
	FlashPhotoApp *prog = new FlashPhotoApp(argc, argv, 800,800,ColorData(1,1,0.95));
	prog->setTool(3);
	prog->mouseDragged(200,100);
	prog->setFileName("Gold standard file here");
	prog->gluiControl(UI_FILE_NAME);
	prog->gluiControl(UI_LOAD_STAMP_BUTTON);//saves canvas
	if (prog->compareBuffers())
	{
		printf("Testing: CalligraphyPen\t SUCCESS\n");
	}
	else
	{
		printf("Testing: CalligraphyPen\t FAIL\n");
	}
	return 0;
}
