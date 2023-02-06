#include "Stop.h"
#include"Actions/Action.h"
#include"ApplicationManager.h"

Stop::Stop(ApplicationManager*pApp,bool IsEnabled):Action(pApp)
{
	Sound = IsEnabled;
}
void Stop::ReadActionParameters()
{


}
void Stop::Execute(bool read)
{
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\stop.wav"), NULL, SND_ASYNC);
	}
	pManager->GetOutput()->PrintMessage("Stop Recording icon");
	pManager->stop_rec();
}
void Stop::undo()
{


}
void Stop::redo()
{


}
void Stop::AddMeUndo(bool redo)
{


}
Stop::~Stop(void)
{
}
void Stop::AddMeRec()
{


}