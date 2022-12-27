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

	if (Sound)
	{
		PlaySound(TEXT("Sounds\\circle.wav"), NULL, SND_ASYNC);
	}

	pOut->PrintMessage("New Hexagon: Click at Center");

	//Read Center and store in point P1
	do {
		pIn->GetPointClicked(p1.x, p1.y);
		if (p1.y <= 50)
			pOut->PrintMessage("Drawing a Hexagon, Can not draw on tool bar");
	} while (p1.y <= 50);


	HexGfxInfo.isFilled = false;	//default is not filled
	
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();
	HexGfxInfo.isFilled = false;

	pOut->ClearStatusBar();

}

void AddHexagon::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(p1, HexGfxInfo);

	//Add the Hexagon to the list of figures
	pManager->AddFigure(H);
}
