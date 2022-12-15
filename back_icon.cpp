#include "back_icon.h"

Backicon::Backicon(ApplicationManager* pApp):Action(pApp)
{
}

void Backicon::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("back icom");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
}

void Backicon::ReadActionParameters()
{
}
