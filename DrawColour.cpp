#include "DrawColour.h"

DrawColour::DrawColour(ApplicationManager* pApp, bool IsEnabled, int color) :Action(pApp)
{
	ACT = color;
	Sound = IsEnabled;
	countHigh = 0;
	countredo = 0;
}

void DrawColour::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on color to color slected figure");
	//find which colour is picked

	switch (ACT)
	{
	case  0:
		c = RED;
		UI.FillColor = RED;
		if (Sound)
		{
			PlaySound(TEXT("Sounds\\red.wav"), NULL, SND_ASYNC);
		}
		pOut->PrintMessage("RED Color");

		break;
	case 1:
		c = BLUE;
		UI.DrawColor = BLUE;

		if (Sound)
		{
			PlaySound(TEXT("Sounds\\blue.wav"), NULL, SND_ASYNC);
		}

		pOut->PrintMessage("Blue Color");
		break;
	case 2:
		c = BLACK;
		UI.DrawColor = BLACK;

		if (Sound)
		{
			PlaySound(TEXT("Sounds\\black.wav"), NULL, SND_ASYNC);
		}
		pOut->PrintMessage("BLACK Color");
		break;
	case 4:
		c = ORANGE;
		UI.DrawColor = ORANGE;
		if (Sound)
		{
			PlaySound(TEXT("Sounds\\orange.wav"), NULL, SND_ASYNC);
		}
		pOut->PrintMessage("ORANGE Color");
		break;
	case 5:
		c = YELLOW;
		UI.DrawColor = YELLOW;
		if (Sound)
		{
			PlaySound(TEXT("Sounds\\yellow.wav"), NULL, SND_ASYNC);
		}
		pOut->PrintMessage("YELLOW Color");
		break;
	case 3:
		c = GREEN;
		UI.DrawColor = GREEN;
		if (Sound)
		{
			PlaySound(TEXT("Sounds\\green.wav"), NULL, SND_ASYNC);
		}
		pOut->PrintMessage("GREEN Color");
		break;
	}
}

void DrawColour::Execute(bool read)

{
	if(read)
	ReadActionParameters();
	CFigure* F = pManager->Returnselectedfig();
	if (F == NULL)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Please select a figure");
		return;
	}
	WasHiglighted[countHigh]=F;
	countHigh++;
	F->ChngDrawClr(c);
}
void DrawColour::AddMeRec()
{

	pManager->AddToRec(this);
}
void DrawColour::AddMeUndo(bool redo)
{
	pManager->AddToUndo(this,redo);

}
void DrawColour::undo()
{
	WasHiglighted[countHigh-1]->undoDC();
	countHigh--;
	countredo++;

}
void DrawColour::redo()
{
	countHigh+=countredo;
	WasHiglighted[countHigh-1]->ChngDrawClr(c);
	countHigh--;
	countHigh+=countredo;
	countredo=0;

}