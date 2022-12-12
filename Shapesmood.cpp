#include "Shapesmood.h"
Shapesmood::Shapesmood(ApplicationManager* pApp) :Action(pApp)
{

}


void Shapesmood::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("DrawMood");
	pOut->ClearToolBar();
	pOut->CreateShapesToolBar();
	
}

void Shapesmood::ReadActionParameters()
{
}
