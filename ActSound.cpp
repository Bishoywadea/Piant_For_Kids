#include "ActSound.h"

ActSound::ActSound(ApplicationManager* pApp, bool* enabled) :Action(pApp), IsEnabled(enabled)
{}

void ActSound::ReadActionParameters()
{}

void ActSound::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (*IsEnabled == 0)
	{
		*IsEnabled = 1;
		UI.Sound = 1;
	}
	else
	{
		UI.Sound = 0;
		*IsEnabled = 0;
	}
}

ActSound::~ActSound()
{}
