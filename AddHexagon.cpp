#include "AddHexagon.h"
#include "AddHexagon.h"


AddHexagon::AddHexagon(ApplicationManager* pApp,bool IsEnabled):Action(pApp)
{
	Sound = IsEnabled;
}

void AddHexagon::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	
	Input* pIn = pManager->GetInput();

	

	pOut->PrintMessage("New Hexagon: Click at Center");

	//Read Center and store in point P1
	
		pIn->GetPointClicked(p1.x, p1.y);
		

	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();
	//HexGfxInfo.isFilled = false;

	pOut->ClearStatusBar();

}

void AddHexagon::Execute(bool read)
{
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\hexagon.wav"), NULL, SND_ASYNC);
	}
	//This action needs to read some parameters first
	if(read)
	ReadActionParameters();

	//Create a Hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(p1, HexGfxInfo);

	//Add the Hexagon to the list of figures
	pManager->AddFigure(H);
	DeletedFig=H;
}
void AddHexagon::undo()
{
	DeletedFig=pManager->Deletelastfig();
}
void AddHexagon::redo()
{
	pManager->AddFigure(DeletedFig);
}
void AddHexagon::AddMeUndo(bool redo)
{
	pManager->AddToUndo(this,redo);

}
void AddHexagon::AddMeRec()
{
	pManager->AddToRec(this);
}