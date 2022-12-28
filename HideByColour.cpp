
#include"HideByColour.h"

HideByColour::HideByColour(ApplicationManager* pApp):ACTHIDE(pApp)
{
	

}
void HideByColour::ReadActionParameters()
{
	
}

void HideByColour::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	do
	{//loop to make sure color picked has at least one fig present

		int ran = rand() % 6;
		if (pManager->getfigcount() == 0)
		{
			return;
		}
		if (!pManager->ifanyiscolored())
		{
			pOut->PrintMessage("No colored figs");
			return;
		}
		switch (ran)
		{
		case ITM_RED:
			c = RED;
			if (pManager->returnfigcolourcount(c))
				pOut->PrintMessage("Pick red figures");

			break;
		case ITM_BLUE:
			c = BLUE;
			if (pManager->returnfigcolourcount(c))
				pOut->PrintMessage("Pick blue figures");
			break;
		case ITM_BLACK:
			c = BLACK;
			if (pManager->returnfigcolourcount(c))
				pOut->PrintMessage("Pick black figures");
			break;
		case ITM_GREEN:
			c = GREEN;
			if (pManager->returnfigcolourcount(c))
				pOut->PrintMessage("Pick green figures");
			break;
		case ITM_ORANGE:
			c = ORANGE;
			if (pManager->returnfigcolourcount(c))
				pOut->PrintMessage("Pick orange figures");
			break;
		case ITM_YELLOW:
			c = YELLOW;
			if (pManager->returnfigcolourcount(c))
				pOut->PrintMessage("Pick yellow figures");
			break;
		}
	} while (pManager->returnfigcolourcount(c) == 0);



	int m=pManager->returnfigcolourcount(c);//find how many figures of certain colour
	int correct = 0;
	int wrong = 0;
	while (correct < m)
	{
		
	
		Point p;
		pIn->GetPointClicked(p.x, p.y);
		
		CFigure*f=pManager->returnfigonpoint(p);
		if (f == nullptr)
		{
			continue;
		}
		if (f->getfigcolour() == c)
		{
			correct++;
			
		}
		else
		{
			wrong++;
		}
		pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct) + "," + to_string(wrong));
		A=new ActDelete(pManager,f);
		A->Execute();
	}//gets all clicks untill user clicks all correct figs
	pOut->ClearStatusBar();
	
	pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct)+", "+to_string(wrong));
	delete this;
	//pOut->ClearStatusBar();
}


