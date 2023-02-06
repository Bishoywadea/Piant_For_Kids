#include "ActDelete.h"
ActDelete::ActDelete(ApplicationManager* pApp,bool IsEnabled) :Action(pApp)
{
	Sound = IsEnabled;
}

void ActDelete::ReadActionParameters()
{
	

	
}

void ActDelete::Execute(bool read)
{
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\Delete.wav"), NULL, SND_ASYNC);
	}
	Output* pOut = pManager->GetOutput();
	CFigure*Fig =pManager->Returnselectedfig();
	DeletedFig=Fig;
	pManager->Deletefig(Fig);//calls delete fig in appmanger class
	pOut->PrintMessage("Selected figure is deleted");
}
void ActDelete::AddMeUndo(bool redo)
{
	pManager->AddToUndo(this,redo);
}
void ActDelete::undo()
{
	pManager->AddFigure(DeletedFig);
}
void ActDelete::redo()
{
	pManager->Deletelastfig();
}
void ActDelete::AddMeRec()
{
	pManager->AddToRec(this);

}