#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp ,bool IsEnabled):Action(pApp)
{
	Sound = IsEnabled;
}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	//RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute(bool read) 
{
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\rectangle.wav"), NULL, SND_ASYNC);
	}
	//This action needs to read some parameters first
	if(read)
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	DeletedFig=R;
}
void AddRectAction::undo()
{
	DeletedFig=pManager->Deletelastfig();
}
void AddRectAction::redo()
{
	pManager->AddFigure(DeletedFig);
}
void AddRectAction::AddMeUndo(bool redo)
{
	pManager->AddToUndo(this,redo);

}
void AddRectAction::AddMeRec()
{
	pManager->AddToRec(this);

}