#include "ActSound.h"

ActSound::ActSound(ApplicationManager* pApp, bool* enabled) :Action(pApp), IsEnabled(enabled)
{}

void ActSound::ReadActionParameters()
{}

void ActSound::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
	if (*IsEnabled == 0)
	{
		*IsEnabled = 1;
		UI.Sound = 1;
		pOut->PrintMessage("Sound On");
	}
	else
	{
		UI.Sound = 0;
		*IsEnabled = 0;
		pOut->PrintMessage("Sound Off");
	}
}
void ActSound::undo()
{
}
void ActSound::redo()
{
	
}

void ActSound::AddMeUndo(bool redo)
{

}
void ActSound::AddMeRec()
{

	
}
ActSound::~ActSound()
{}
