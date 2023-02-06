
#include"AddCircle.h"
AddCircle::AddCircle(ApplicationManager* pApp,bool IsEnabled):Action(pApp)
{
	Sound = IsEnabled;
}

void AddCircle::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	
	pOut->PrintMessage("DRAW CIRCLE");
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	

	//CircGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	

	pOut->ClearStatusBar();

}
void AddCircle::Execute(bool read)
{
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\circle.wav"), NULL, SND_ASYNC);
	}
	//This action needs to read some parameters first
	if(read)
	ReadActionParameters();

	//Create a Circle with the parameters read from the user
	Ccircle* C = new Ccircle(P1,P2, CircGfxInfo);

	//Add the Circle to the list of figures
	pManager->AddFigure(C);
	DeletedFig=C;
}
void AddCircle::AddMeUndo(bool redo)
{
	pManager->AddToUndo(this,redo);

}
void AddCircle::undo()
{
	DeletedFig=pManager->Deletelastfig();
}
void AddCircle::redo()
{
	pManager->AddFigure(DeletedFig);

}
void AddCircle::AddMeRec()
{
	pManager->AddToRec(this);

}