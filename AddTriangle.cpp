#include "AddTriangle.h"

AddTriangle::AddTriangle(ApplicationManager* pApp):Action(pApp)
{
	
}

void AddTriangle::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	// 2.3.1 - Drawing non-filled and non-Highlighted Triangle
	pOut->PrintMessage("Drawing a Triangle,  Click three points");
	do {
		pIn->GetPointClicked(P1.x, P1.y);
		if (P1.y < UI.ToolBarHeight)
			pOut->PrintMessage("Drawing a Triangle, Can not draw on tool bar");
	} while (P1.y < UI.ToolBarHeight);
	pOut->PrintMessage("Drawing a Triangle, Click another two points");
	do {
		pIn->GetPointClicked(P2.x, P2.y);
		if (P2.y < UI.ToolBarHeight)
			pOut->PrintMessage("Drawing a Triangle, Can not draw on tool bar");
	} while (P2.y < UI.ToolBarHeight);
	pOut->PrintMessage("Drawing a Triangle, Click another point");
	do {
		pIn->GetPointClicked(P3.x, P3.y);
		if (P3.y < UI.ToolBarHeight)
			pOut->PrintMessage("Drawing a Triangle, Can not draw on tool bar");
	} while (P1.y < UI.ToolBarHeight || P2.y < UI.ToolBarHeight || P3.y < UI.ToolBarHeight);
	TriGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddTriangle::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2,P3, TriGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(T);
}
