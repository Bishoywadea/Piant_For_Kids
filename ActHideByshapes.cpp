#include"ActHideByshapes.h"
#include"ActDelete.h"
#include"ACTHIDE.h"
#include <time.h>;
#pragma once



HideByshapes::HideByshapes(ApplicationManager* pApp):Action(pApp)
{
	
}

void HideByshapes::ReadActionParameters()
{

}

void HideByshapes::Execute(bool b)
{
	ACTHIDE h(pManager);
	int correct = 0;
	int wrong = 0;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	figcounter = 0;

	srand(time(NULL));//random seed
	bool k = 1;
	int ran = rand() % 5;

	if (!pManager->getfigcount())
	{
		pOut->PrintMessage("No figs");
		return;
	}
	do
	{//loop to make sure color picked has at least one fig present

		int ran = rand() % 5;
		if (pManager->getcertainfigcount(ran))
		{
			pOut->PrintMessage("Pick" + turnenumshapesintostring(ran));
			figitems = ran;
			k = 0;
		}

	} while (k);
	figcounter = pManager->getcertainfigcount(figitems);
	
	while (correct< figcounter)
	{
		Point p;
		pIn->GetPointClicked(p.x, p.y);
		CFigure* fig = pManager->GetFigure(p.x, p.y);
		if (fig != NULL)
		{
			if (fig->iffigtype() == figitems)
			{
				correct++;
			}
			else
			{
				wrong++;
			}
			pOut->PrintMessage("no of correct answers" + to_string(correct) + " " + " no of wrong answers" + to_string(wrong));
			pManager->Deletefig(fig);
			pManager->UpdateInterface();
			
			
		}
		else
		{
			pOut->PrintMessage("Please click on fig");
			continue;
		}
	}
	pOut->ClearStatusBar();
	pOut->PrintMessage("no of correct answers" + to_string(correct) + " " + " no of wrong answers" + to_string(wrong));

}

void HideByshapes::AddMeUndo(bool redo)
{
}

void HideByshapes::AddMeRec()
{
}

void HideByshapes::undo()
{
}

void HideByshapes::redo()
{
}



