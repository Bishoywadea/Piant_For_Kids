#include "ActDelete.h"
ActDelete::ActDelete(ApplicationManager* pApp) :Action(pApp)
{

}

void ActDelete::ReadActionParameters()
{
	

	
}

void ActDelete::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure*Fig =pManager->Returnselectedfig();
	pManager->Deletefig(Fig);//calls delete fig in appmanger class
	pOut->PrintMessage("Selected figure is deleted");
}
void ActDelete::undo()
{
	pManager->ReDraw();
}
void ActDelete::redo()
{
	pManager->Deletelastfig();
}