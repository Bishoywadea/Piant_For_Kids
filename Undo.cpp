#include "Undo.h"
#include"Actions/Action.h"
#include"ApplicationManager.h"
Undo::Undo(ApplicationManager*pApp,bool IsEnabled):Action(pApp)
{
	Sound = IsEnabled;
}
void Undo::ReadActionParameters()
{


}

void Undo::Execute(bool read)
{   
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\undo.wav"), NULL, SND_ASYNC);
	}
pManager->GetOutput()->PrintMessage("Undo icon");
Action* ptr=pManager->GetLastUndo();
if(ptr!=NULL)
{
	ptr->undo();
	pManager->AddToRedo();
	
}
else
	 pManager->GetOutput()->PrintMessage("No Actions done to undo");
}
void Undo::undo()
{

}
void Undo::redo()
{

}
void Undo::AddMeUndo(bool redo)
{


}
void Undo::AddMeRec()
{
	pManager->AddToRec(this);
}
Undo::~Undo()
{
}