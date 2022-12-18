#include "Createplaymood.h"
Createplaymood::Createplaymood(ApplicationManager* pApp) :Action(pApp)
{

}

void Createplaymood::ReadActionParameters()
{
}

void Createplaymood::Execute()
{
	Output* pOut = pManager->GetOutput();
	
	pOut->PrintMessage("PlayMood");
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();

}
