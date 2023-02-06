#include"HideByColour.h"

#include"ActDelete.h"
#include <time.h>;
HideByColour::HideByColour(ApplicationManager* pApp):Action(pApp)
{
	

}
void HideByColour::ReadActionParameters()
{
	
}

void HideByColour::Execute(bool b)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->getfigcount() == 0)
	{
		pOut->PrintMessage("No  figures are present");
		return;
	}
	if (pManager->returnfigcolourcount(-1) == pManager->getfigcount())
	{
		pOut->PrintMessage("No colored figs,click to continue");

		return;
	}
	ACTHIDE h(pManager);

	bool ok=1;
	int c1;
	srand(time(NULL));//random seed
	do
	{//loop to make sure color picked has at least one fig present

		int ran = rand() % 6;

		
		
		switch (ran)
		{
		case ITM_RED:
			c1 = 0;
			if (pManager->returnfigcolourcount(0))
			{
				pOut->PrintMessage("Pick red figures,click to continue");
				ok = false;
				break;
			}
			else
				continue;


		case ITM_BLUE:
			c1 = 1;
			if (pManager->returnfigcolourcount(1)){
				ok = false;
				pOut->PrintMessage("Pick blue figures,click to continue");
		//	pIn->GetUserAction();
			break;
		}
		else
			continue;
		case ITM_BLACK:
			c1 = 2;
			if (pManager->returnfigcolourcount(2)){
				ok = false;
				pOut->PrintMessage("Pick black figures,click to continue");
			//pIn->GetUserAction();
			break;
		}
		else
			continue;
		case ITM_GREEN:
			c1 = 3;
			if (pManager->returnfigcolourcount(3)){
				ok = false;
				pOut->PrintMessage("Pick green figures,click to continue");
				break;
			}
			else
				continue;
		case ITM_ORANGE:
			c1 = 4;
			if (pManager->returnfigcolourcount(4)){
				ok = false;
				pOut->PrintMessage("Pick orange figures,click to continue");
				break;
			}
			else
				continue;
		case ITM_YELLOW:
			c1 = 5;
			if (pManager->returnfigcolourcount(5)){
				ok = false;
				pOut->PrintMessage("Pick yellow figures,click to continue");
				break;
			}
			else
				continue;

			
		}
	} while (ok);

	int m=pManager->returnfigcolourcount(c1);//find how many figures of certain colour
	int correct = 0;
	int wrong = 0;
	while (correct < m)
	{
		
	
		Point p;
		pIn->GetPointClicked(p.x, p.y);
		
		CFigure * f = pManager->GetFigure(p.x, p.y);
		if (f == nullptr)
		{
			continue;
		}
		if (f->getfigcolour() == c1)
		{
			correct++;
			
		}
		else
		{
			wrong++;
		}
		pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct) + "," + to_string(wrong));
		pManager->Deletefig(f);
		pManager->UpdateInterface();
	}//gets all clicks untill user clicks all correct figs
	pOut->ClearStatusBar();
	
	pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct)+", "+to_string(wrong));
	
	//pOut->ClearStatusBar();
}

void HideByColour::AddMeUndo(bool redo)
{
}

void HideByColour::AddMeRec()
{
}

void HideByColour::undo()
{
}

void HideByColour::redo()
{
}





