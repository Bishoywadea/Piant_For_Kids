#include "ActionDrag.h"
#include<iostream>
#include"Figures/CFigure.h"
ActionDrag::ActionDrag(ApplicationManager* pApp) :Action(pApp)
{

}

void ActionDrag::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please click to select figure");
	pIn->GetPointClicked(P.x, P.y);
	SelectedFig = pManager->GetFigure(P.x, P.y);
	if (SelectedFig != NULL)
	{
		while (1)
		{
			//GetAsyncKeyState(0x01)
			pIn->watchDrag(stat, btn, P.x, P.y);
			std::cout << P.x << " : " << P.y << "   " << stat << "       " << btn << std::endl;
			SelectedFig->MOVE(P);
			pManager->UpdateInterface();
			SelectedFig = pManager->GetFigure(P.x, P.y);
			if (stat == 1)
			{
				break;
			}
			Sleep(5);
		}
	}

	pOut->ClearStatusBar();
}

//Execute the action
void ActionDrag::Execute()
{

	ReadActionParameters();

}