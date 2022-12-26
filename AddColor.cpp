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
		 UI.FillColor = RED;
		// UI.FillColor = RED;
		 pOut->PrintMessage("RED Color");
		 break;
	 case ACT_BLUE:
		 c = BLUE;
		 UI.FillColor = BLUE;

		// UI.FillColor = BLUE;

		 pOut->PrintMessage("Blue Color");
		 break;
	 case ACT_BLACK:
		 c = BLACK;
		 UI.FillColor = BLACK;
		
		 //UI.FillColor = BLACK;
		 pOut->PrintMessage("BLACK Color");
		 break;
	 case ACT_ORANGE:
		 c = ORANGE;
		 UI.FillColor = ORANGE;
		 //UI.FillColor = ORANGE;
		 pOut->PrintMessage("ORANGE Color");
		 break;
	 case ACT_YELLOW:
		 c = YELLOW;
		 UI.FillColor = YELLOW;
		 //UI.FillColor = YELLOW;
		 pOut->PrintMessage("YELLOW Color");
		 break;
	 case ACT_GREEN:
		 c = GREEN;
		 UI.FillColor = GREEN;
		 //UI.FillColor = GREEN;
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
