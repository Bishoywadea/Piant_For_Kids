#include "Redo.h"
#include"Actions/Action.h"
#include"ApplicationManager.h"

Redo::Redo(ApplicationManager*pApp,bool IsEnabled):Action(pApp)
{
	Sound = IsEnabled;
}
void Redo::ReadActionParameters()
{


}
void Redo::Execute(bool read)
{   
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\redo.wav"), NULL, SND_ASYNC);
	}
	pManager->GetOutput()->PrintMessage("Redo icon");
    Action* ptr=pManager->GetLastRedo();
if(ptr!=NULL)
{
	ptr->redo();
	ptr->AddMeUndo(0);
}
else
	 pManager->GetOutput()->PrintMessage("No Actions done to redo");
}
void Redo::undo()
{


}
void Redo::redo()
{


}
void Redo::AddMeUndo(bool redo)
{


}
Redo::~Redo()
{
}
void Redo::AddMeRec()
{
	pManager->AddToRec(this);

}
