#include "AddSquare.h"
#include <stdlib.h>

AddSquare::AddSquare(ApplicationManager* pApp, bool IsEnabled):Action(pApp)
{
	Sound=IsEnabled;
}

void AddSquare::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("New Square: Click at Center");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	

	//SquaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddSquare::Execute(bool read)
{
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\Square.wav"), NULL, SND_ASYNC);
	}
	//This action needs to read some parameters first
	if(read)
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	Square* S = new Square(P1, SquaGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(S);
	DeletedFig=S;
}
void AddSquare::undo()
{
	DeletedFig=pManager->Deletelastfig();
}
void AddSquare::redo()
{
	pManager->AddFigure(DeletedFig);
}
void AddSquare::AddMeUndo(bool redo)
{
	pManager->AddToUndo(this,redo);

}
void AddSquare::AddMeRec()
{
	pManager->AddToRec(this);

}