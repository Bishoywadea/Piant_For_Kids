#include "MoveAction.h"

MoveAction::MoveAction(ApplicationManager* pApp,bool IsEnabled) :Action(pApp)
{
	Sound = IsEnabled;
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

void MoveAction::Execute(bool read)
{
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\move.wav"), NULL, SND_ASYNC);
	}
	Fig = pManager->Returnselectedfig();
	if (Fig == NULL)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("PLEASE select a figure");
		return;

	}
	if(read)
	ReadActionParameters();
	Fig->MOVE(p1);//this move function is overridden in each CFigures class
	unp1=Fig->getcenter();
	
	
}
void MoveAction::undo()
{
	
	Fig->MOVE(unp1);
}
void MoveAction::redo()
{
	
	Fig->MOVE(p1);
}

void MoveAction::AddMeUndo(bool redo)
{
	pManager->AddToUndo(this,redo);

}
void MoveAction::AddMeRec()
{

	pManager->AddToRec(this);
}