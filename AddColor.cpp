#include "AddColor.h"

AddColor::AddColor(ApplicationManager* pApp):Action(pApp)
{
}

void AddColor::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearToolBar();
	pOut->CreateColourToolBar();

	pOut->PrintMessage("Click on color to color slected figure");
	//find which colour is picked
	ActionType ACT;

	 ACT = pIn->GetUserAction();
	 switch (ACT)
	 {
	 case ACT_RED:
		 c = RED;
		 pOut->PrintMessage("RED Color");
		 break;
	 case ACT_BLUE:
		 c = BLUE;
		 pOut->PrintMessage("Blue Color");
		 break;
	 case ACT_BLACK:
		 c = BLACK;
		 pOut->PrintMessage("BLACK Color");
		 break;
	 case ACT_ORANGE:
		 c = ORANGE;
		 pOut->PrintMessage("ORANGE Color");
		 break;
	 case ACT_YELLOW:
		 c = YELLOW;
		 pOut->PrintMessage("YELLOW Color");
		 break;
	 case ACT_GREEN:
		 c = GREEN;
		 pOut->PrintMessage("GREEN Color");
		 break;
	 }

	
	


}

void AddColor::Execute()
{
	ReadActionParameters();
	CFigure* F = pManager->Returnselectedfig();
	if (F == NULL)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Please select a figure");
		return;
	}
	
	F->ChngFillClr(c);

}
