#include "MIAApp.h"

int main(int argc,char *argv[])
{
	MIAApp *prog = new MIAApp(argc, argv, 800,800,ColorData(1,1,0.95));
	prog->setTool(0);
	prog->leftMouseDown(200,100);
	prog->setFileName("golds/mstamp_gold.png");
	prog->gluiControl(MIAApp::UI_FILE_NAME);
	prog->gluiControl(MIAApp::UI_SAVE_CANVAS_BUTTON);//saves canvas
/*	if (prog->compareBuffers())
	{
		printf("Testing: Pen\t SUCCESS\n");
	}
	else
	{
		printf("Testing: Pen\n FAIL\n");
	}*/
	return 0;
}
