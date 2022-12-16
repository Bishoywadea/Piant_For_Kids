#include "SelectAction.h"
#include"Actions/Action.h"
#include"ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please click to select figure");

	pIn->GetPointClicked(P.x, P.y);

	pOut->ClearStatusBar();
}

//Execute the action
void SelectAction::Execute()
{

	ReadActionParameters();

	//check if the point clicked is on fig //BISHOY
	SelectedFig = pManager->GetFigure(P.x, P.y);

	//to select or unselect a fig
	if (SelectedFig != NULL) {
		if (SelectedFig->IsSelected())
			Unselected();
		else
			Selected();
	}
}

void SelectAction::Selected() {
	SelectedFig->SetSelected(true); //Sets the figure as "selected"
	Output* pOut = pManager->GetOutput(); //Get a Pointer to the Output Interface
	SelectedFig->PrintInfo(pOut); //Print the selected figure info on the status bar
}

void SelectAction::Unselected() {
	SelectedFig->SetSelected(false); //Sets the figure as "unselected"
}