#include "DrawColour.h"

DrawColour::DrawColour(ApplicationManager* pApp):Action(pApp)
{



}

void DrawColour::ReadActionParameters()
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
		UI.DrawColor = RED;
		pOut->PrintMessage("RED Color");
		break;
	case ACT_BLUE:
		c = BLUE;
		UI.DrawColor = BLUE;

		pOut->PrintMessage("Blue Color");
		break;
	case ACT_BLACK:
		c = BLACK;
		UI.DrawColor = BLACK;

		pOut->PrintMessage("BLACK Color");
		break;
	case ACT_ORANGE:
		c = ORANGE;
		UI.DrawColor = ORANGE;
		pOut->PrintMessage("ORANGE Color");
		break;
	case ACT_YELLOW:
		c = YELLOW;
		UI.DrawColor = YELLOW;
		pOut->PrintMessage("YELLOW Color");
		break;
	case ACT_GREEN:
		c = GREEN;
		UI.DrawColor = GREEN;
		pOut->PrintMessage("GREEN Color");
		break;
	}


}

void DrawColour::Execute()

{
	ReadActionParameters();
	CFigure* F = pManager->Returnselectedfig();
	if (F == NULL)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Please select a figure");
		return;
	}

	F->ChngDrawClr(c);
}
