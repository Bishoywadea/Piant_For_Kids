#include "Createplaymood.h"
Createplaymood::Createplaymood(ApplicationManager* pApp) :Action(pApp)
{

}

void Createplaymood::ReadActionParameters()
{
}

void Createplaymood::Execute(bool b)
{
	Output* pOut = pManager->GetOutput();
	
	pOut->PrintMessage("PlayMood");
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();

}
void Createplaymood::undo()
{


}
void Createplaymood::redo()
{

}
void Createplaymood::AddMeUndo(bool redo)
{


}
void Createplaymood::AddMeRec()
{


}