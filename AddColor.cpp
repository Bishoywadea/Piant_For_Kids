#include "AddColor.h"

AddColor::AddColor(ApplicationManager* pApp, bool IsEnabled, int color) :Action(pApp)
{
	ACT = color;
	Sound = IsEnabled;
	countfilled = 0;
	countredo = 0;
}

void AddColor::ReadActionParameters()
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
		UI.FillColor = BLUE;

		if (Sound)
		{
			PlaySound(TEXT("Sounds\\blue.wav"), NULL, SND_ASYNC);
		}

		pOut->PrintMessage("Blue Color");
		break;
	case 2:
		c = BLACK;
		UI.FillColor = BLACK;

		if (Sound)
		{
			PlaySound(TEXT("Sounds\\black.wav"), NULL, SND_ASYNC);
		}
		pOut->PrintMessage("BLACK Color");
		break;
	case 4:
		c = ORANGE;
		UI.FillColor = ORANGE;
		if (Sound)
		{
			PlaySound(TEXT("Sounds\\orange.wav"), NULL, SND_ASYNC);
		}
		pOut->PrintMessage("ORANGE Color");
		break;
	case 5:
		c = YELLOW;
		UI.FillColor = YELLOW;
		if (Sound)
		{
			PlaySound(TEXT("Sounds\\yellow.wav"), NULL, SND_ASYNC);
		}
		pOut->PrintMessage("YELLOW Color");
		break;
	case 3:
		c = GREEN;
		UI.FillColor = GREEN;
		if (Sound)
		{
			PlaySound(TEXT("Sounds\\green.wav"), NULL, SND_ASYNC);
		}
		pOut->PrintMessage("GREEN Color");
		break;
	}
}

void AddColor::Execute(bool read)
{
	if (read)
		ReadActionParameters();
	F = pManager->Returnselectedfig();
	if (F == NULL)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Please select a figure");
		return;
	}
	Wasfilled[countfilled] = F;
	countfilled++;
	F->ChngFillClr(c);

}
void AddColor::undo()
{
	Wasfilled[countfilled - 1]->undoFC();
	countfilled--;
	countredo++;

}
void AddColor::redo()
{
	countfilled += countredo;
	Wasfilled[countfilled - 1]->ChngFillClr(c);
	countfilled--;
	countfilled += countredo;
	countredo = 0;
}
void AddColor::AddMeUndo(bool redo)
{
	pManager->AddToUndo(this,redo);

}
void AddColor::AddMeRec()
{
	pManager->AddToRec(this);
}