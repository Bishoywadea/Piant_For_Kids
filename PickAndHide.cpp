#include "PickAndHide.h"
#include <time.h>



PickAndHideByShapes::PickAndHideByShapes(ApplicationManager* pApp):Action(pApp)
{
	pManager = pApp;
}
void PickAndHideByShapes::ReadActionParameters()
{
}
void PickAndHideByShapes::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	srand(time(0));

	int n = rand() % 5;
	CFigure* c1;
	//ActionType shape;
	//ShapesMenuItem n;
	int nomofhidden=0;
	switch (n)
	{
	case ITM_RECT:
		pOut->PrintMessage("Pick All Rectangles");
	
		break;
	case ITM_SQU:
			pOut->PrintMessage("Pick All Squares");
			break;
	case ITM_CIR:

		pOut->PrintMessage("Pick All Circles");
		break;
	case ITM_HEX:
		pOut->PrintMessage("Pick All Hexagons");
		break;
	case ITM_TRI:
		pOut->PrintMessage("Pick All Hexagons");
		break;

	}
	int nom=pManager->returnfigcount(n);
	int correct = 0;
	int incorrect = 0;
	

	while (correct < nom)
	{
		Point p;
		 pIn->GetPointClicked(p.x,p.y);
		 if (pManager->returnfigonpoint(p))
		 {
			 c1 = (pManager->returnfigonpoint(p));
			 if (c1->Returnshapestype() == n)
			 {
				 correct++;
				 fighidden[nomofhidden] = c1;
				 c1->ChngDrawClr(UI.BkGrndColor);
				 c1->ChngFillClr(UI.BkGrndColor);
				 c1->Draw(pOut);

			 }
			 else
			 {
				 incorrect--;
				 c1->ChngDrawClr(UI.BkGrndColor);
				 c1->ChngFillClr(UI.BkGrndColor);
				 c1->Draw(pOut);

			 }

		 }
		 else
		 {
			 pOut->PrintMessage("Please click on a fig");
		 }

	}
	string correctfalse = correct + " " + false;
	pOut->PrintMessage("correct answers & false answers are " + correctfalse);
	
}

void PickAndHideByShapes::hide()
{

}

PickAndHideByShapes::~PickAndHideByShapes()
{
	for (int i = 0; i < 200; i++)
	{
		if (fighidden[i] != NULL)
		{
			delete fighidden[i];
		}
	}
}


