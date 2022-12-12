
#include"AddCircle.h"
AddCircle::AddCircle(ApplicationManager* pApp):Action(pApp)
{
	
}

void AddCircle::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("DRAW CIRCLE");
	Input* pIn = pManager->GetInput();
	//check bounds for circle
	do{
	pIn->GetPointClicked(P1.x, P1.y);
	if (P1.y <= 50)
	{
		pOut->PrintMessage("Drawing a Circle, Can not draw on tool bar");
	}
}while (P1.y <= 50);
do
{
	pIn->GetPointClicked(P2.x, P2.y);
	if (P2.y <= 50)
		pOut->PrintMessage("Drawing a Circle, Can not draw on tool bar");
} while (P2.y <= 50);
if (sqrt(pow((P1.x - P2.x), 2) + pow((P1.y) - (P2.y), 2)) > P1.y - 50)
{
	P1.y = 325;
	P2.x = P1.x;
	P2.y = 50;
}

	CircGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}
void AddCircle::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Circle with the parameters read from the user
	Ccircle* C = new Ccircle(P1,P2, CircGfxInfo);

	//Add the Circle to the list of figures
	pManager->AddFigure(C);
}