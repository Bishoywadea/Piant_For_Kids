#include "MoveAction.h"

MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp)
{
}

void MoveAction::ReadActionParameters()
{
	

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();




		pOut->PrintMessage("Click on point you want to move fig to");

		//Read Center and store in point P1
		pIn->GetPointClicked(p1.x, p1.y);
		pOut->ClearStatusBar();
	
	
		//pOut->PrintMessage("Click on selected point");
	

}

void MoveAction::Execute()
{
	Fig = pManager->Returnselectedfig();
	if (Fig == NULL)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("PLEASE select a figure");
		return;

	}
	ReadActionParameters();
	CFigure* oldfig = Fig;
	Fig->MOVE(p1);//this move function is over ridden in each CFigures class
	
}
