#include "Actclearall.h"
Actclearall::Actclearall(ApplicationManager* pApp):Action(pApp)
{
	
}
void Actclearall::ReadActionParameters()
{
}
void Actclearall::Execute(bool b)
{
	Output* pOut= pManager->GetOutput();
	
	pManager->Clearall();
	pManager->clearredo();
	pManager->clearundo();
	pManager->clearrecordings();
	pOut->PrintMessage("Window is cleared");

}

void Actclearall::AddMeUndo(bool redo)
{
}

void Actclearall::AddMeRec()
{
}

void Actclearall::undo()
{
}

void Actclearall::redo()
{
}
