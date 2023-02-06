#include "DrawColorMenu.h"

DrawColorMenu::DrawColorMenu(ApplicationManager* pApp) :Action(pApp)
{
}

void DrawColorMenu::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearToolBar();
	pOut->CreateDrawColourToolBar();
}

void DrawColorMenu::Execute(bool read)
{
	ReadActionParameters();
}

void DrawColorMenu::AddMeUndo(bool redo)
{
}

void DrawColorMenu::undo()
{
}

void DrawColorMenu::redo()
{
}

void DrawColorMenu::AddMeRec()
{
	pManager->AddToRec(this);
}
