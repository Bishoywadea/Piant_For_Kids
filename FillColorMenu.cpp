#include "FillColorMenu.h"

FillColorMenu::FillColorMenu(ApplicationManager* pApp) :Action(pApp)
{
}

void FillColorMenu::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearToolBar();
	pOut->CreateFillColourToolBar();
}

void FillColorMenu::Execute(bool read)
{
	ReadActionParameters();
}

void FillColorMenu::AddMeUndo(bool redo)
{
}

void FillColorMenu::undo()
{
}

void FillColorMenu::redo()
{
}

void FillColorMenu::AddMeRec()
{
	pManager->AddToRec(this);
}
