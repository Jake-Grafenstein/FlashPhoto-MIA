#include "../FlashPhoto/FlashPhoto.h"

int main(int argc,char *argv[])
{
	FlashPhotoApp *prog = new FlashPhotoApp(argc, argv, 800,800,ColorData(1,1,0.95));
	//need function to set m_curTool manually
	prog->mouseDragged(200,100);
	prog->setFileName("Gold standard file here");
	prog->gluiControl(UI_FILE_NAME);
	prog->gluiControl(UI_LOAD_STAMP_BUTTON);//saves canvas
	if (prog->compareBuffers())
	{
		printf("Testing: Pen\t SUCCESS\n");
	}
	else
	{
		printf("Testing: Pen\n FAIL\n");
	}
	return 0;
}
