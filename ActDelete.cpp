#include "ActDelete.h"
ActDelete::ActDelete(ApplicationManager* pApp, CFigure* f) :Action(pApp)
{
	fig = f;
}

void ActDelete::ReadActionParameters()
{
	

	
}

void ActDelete::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (fig == nullptr)
	{
		fig = pManager->Returnselectedfig();


		pManager->Deletefig(fig);//callls delete fig in appmanger class
		pOut->PrintMessage("Selected figure is deleted");
	}
	else
	{
		pManager->Deletefig(fig);//callls delete fig in appmanger class
		pManager->UpdateInterface();
	}
}
