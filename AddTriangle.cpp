#include "AddTriangle.h"

AddTriangle::AddTriangle(ApplicationManager* pApp,bool IsEnabled):Action(pApp)
{
	Sound = IsEnabled;
}

void AddTriangle::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	// 2.3.1 - Drawing non-filled and non-Highlighted Triangle
	pOut->PrintMessage("Drawing a Triangle,  Click three points");
	
		pIn->GetPointClicked(P1.x, P1.y);
		pIn->GetPointClicked(P2.x, P2.y);
		pIn->GetPointClicked(P3.x, P3.y);
		
	//TriGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddTriangle::Execute(bool read)
{
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\triangle.wav"), NULL, SND_ASYNC);
	}
	//This action needs to read some parameters first
	if(read)
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2,P3, TriGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(T);
	DeletedFig=T;
}
void AddTriangle::undo()
{
	DeletedFig=pManager->Deletelastfig();
}
void AddTriangle::redo()
{
	pManager->AddFigure(DeletedFig);
}
void AddTriangle::AddMeUndo(bool redo)
{
	pManager->AddToUndo(this,redo);

}
void AddTriangle::AddMeRec()
{
	pManager->AddToRec(this);

}