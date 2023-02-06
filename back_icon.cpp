#include "back_icon.h"

Backicon::Backicon(ApplicationManager* pApp):Action(pApp)
{
}

void Backicon::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
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
void Backicon::AddMeUndo(bool redo)
{


}
void Backicon::AddMeRec()
{
	pManager->AddToRec(this);

}