#include "Shapesmood.h"
Shapesmood::Shapesmood(ApplicationManager* pApp) :Action(pApp)
{

}


void Shapesmood::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("DrawMood");
	pOut->ClearToolBar();
	pOut->CreateShapesToolBar();
	
}

void Shapesmood::ReadActionParameters()
{
}
void Shapesmood::undo()
{

}
void Shapesmood::redo()
{
	
	
}
void Shapesmood::AddMeUndo(bool redo)
{


}
void Shapesmood::AddMeRec()
{
	pManager->AddToRec(this);

}