#include "back_icon.h"

Backicon::Backicon(ApplicationManager* pApp):Action(pApp)
{
}

void Backicon::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("back icon");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
}

void Backicon::ReadActionParameters()
{
}
void Backicon::undo()
{

}
void Backicon::redo()
{

}