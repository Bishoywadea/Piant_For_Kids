#include "Exit.h"
#include"Actions/Action.h"
#include"ApplicationManager.h"


Exit::Exit(ApplicationManager*pApp,bool IsEnabled):Action(pApp)
{
	Sound = IsEnabled;
}

void Exit::ReadActionParameters()
{


}

void Exit::Execute(bool read)
{
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\Exit.wav"), NULL, SND_ASYNC);
	}
	Output* pOut= pManager->GetOutput();
	
	pManager->Clearall();
	pManager->clearredo();
	pManager->clearundo();
	pManager->clearrecordings();
	pOut->PrintMessage("Window is cleared");
}
void Exit::undo()
{

}
void Exit::redo()
{

}
void Exit::AddMeUndo(bool redo)
{


}
void Exit::AddMeRec()
{
	
}
Exit::~Exit()
{
}

