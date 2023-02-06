#include "ActionDrag.h"
#include"Figures/CFigure.h"
#include<iostream>
using namespace std;
ActionDrag::ActionDrag(ApplicationManager* pApp):Action(pApp)
{
	btn = LEFT_BUTTON;
	flag = 1;
}

void ActionDrag::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("please hold the click and move the selected fig");
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
void ActionDrag::Execute(bool read)
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
		SelectedFig->MOVE(P);
		pManager->UpdateInterface();
		Sleep(5);
	}
}
void ActionDrag::redo()
{


}
void ActionDrag::undo()
{
	

}
void ActionDrag::AddMeUndo(bool redo)
{


}
void ActionDrag::AddMeRec()
{
	pManager->AddToRec(this);

}
