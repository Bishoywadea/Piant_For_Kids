#include "ActionResize.h"
#include"Figures/CFigure.h"

ActionResize::ActionResize(ApplicationManager* pApp) :Action(pApp)
{
	btn = LEFT_BUTTON;
	flag = 1;
}

void ActionResize::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("please click on a corner and hold to resize");
	if (flag)
	{
		while (1)
		{
			pIn->mousestate(stat, btn, P.x, P.y);
			if (stat == 1)
			{
				break;
			}
		}
	}
	pIn->mousestate(stat, btn, P.x, P.y);
		

	pOut->ClearStatusBar();
}

//Execute the action
void ActionResize::Execute(bool read)
{
	SelectedFig = pManager->Returnselectedfig();
	if (SelectedFig == NULL)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("PLEASE select a figure");
		return;

	}
	ReadActionParameters();
	while (stat == 1)
	{
		flag = 0;
		ReadActionParameters();
		SelectedFig->GetTheCorner(P);
		SelectedFig->Resize(P);
		pManager->UpdateInterface();
		Sleep(5);
	}
}
void ActionResize::redo()
{


}
void ActionResize::undo()
{


}
void ActionResize::AddMeUndo(bool redo)
{


}
void ActionResize::AddMeRec()
{


}