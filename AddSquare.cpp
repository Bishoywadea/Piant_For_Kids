#include "AddSquare.h"

AddSquare::AddSquare(ApplicationManager* pApp):Action(pApp)
{
	
}
#include "Actions/Action.h"
void AddSquare::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at Center");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	SquaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddSquare::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	Square* S = new Square(P1, SquaGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(S);
}
void AddSquare::undo()
{
	DeletedFig=pManager->Deletelastfig();
}
void AddSquare::redo()
{
	pManager->AddFigure(DeletedFig);
}