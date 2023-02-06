#include "HideShapesAndColors.h"
#include"ACTHIDE.h"
#include <time.h>
HideShapesAndColors::HideShapesAndColors(ApplicationManager* pApp):Action(pApp)
{
}

void HideShapesAndColors::ReadActionParameters()
{
}

void HideShapesAndColors::Execute(bool b)
{

	int correct = 0;
	int wrong = 0;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	

	srand(time(NULL));//random seed
	//bool k = 0;

	if (pManager->getfigcount() == 0)
	{
		pOut->PrintMessage("No  figures are present");
		return;
	}
	if (pManager->returnfigcolourcount(-1)== pManager->getfigcount())
	{
		pOut->PrintMessage("No colored figs,click to continue");

		return;
	}
	ACTHIDE h(pManager);
	bool ok = 1;
	int color1;
	do
	{
		figitems = rand() % 5;
	    color1 = rand() % 6;
		if (pManager->returnfigsofcertaintypeandcolor(color1, figitems))
		{
			
			pOut->PrintMessage("pick " + turnenumshapesintostring(figitems) + " color:" + turnenumcolorsintostring(color1));
			ok = 0;
		}


	} while (ok);
	int m = pManager->returnfigsofcertaintypeandcolor(color1, figitems);
	while (correct < m)
	{
		Point p;
		pIn->GetPointClicked(p.x, p.y);
		CFigure* fig = pManager->GetFigure(p.x, p.y);
			if (fig) {
				if (fig->iffigtype() == figitems && fig->getfigcolour() == color1)
				{
					correct++;
				}
				else
				{
					wrong++;
				}
				pOut->PrintMessage("no of correct" + to_string(correct) + "no of wrong" + to_string(wrong));
				pManager->Deletefig(fig);
				pManager->UpdateInterface();
				
			}
			else
			{
				continue;
			}
	}
	pOut->PrintMessage("no of correct" + to_string(correct) + "no of wrong" + to_string(wrong));

}

void HideShapesAndColors::AddMeUndo(bool redo)
{
}

void HideShapesAndColors::AddMeRec()
{
}

void HideShapesAndColors::undo()
{
}

void HideShapesAndColors::redo()
{
}
