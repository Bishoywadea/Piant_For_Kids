#include "ActHideByshapes.h"


//HideByshapes::HideByshapes(ApplicationManager* pApp):Action(pApp)
//{
//	string h = to_string(i) + ".txt";
//	A = new SaveAction(pManager, pManager->getfigcount(), h);
//	A->Execute();
//}

HideByshapes::HideByshapes(ApplicationManager* pApp):ACTHIDE(pApp)
{
}

void HideByshapes::ReadActionParameters()
{
}

void HideByshapes::Execute()
{
	int correct = 0;
	int wrong = 0;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int m=0;

	srand(time(NULL));//random seed
	bool k = 0;
	int ran = rand() % 5;
	if (pManager->getfigcount() == 0)
	{
		return;
	}
	if (!pManager->getfigcount())
	{
		pOut->PrintMessage("No figs");
		return;
	}
	do
	{//loop to make sure color picked has at least one fig present

		int ran = rand() % 5;
	
	
		switch (ran)
		{
		case ITM_RECT:
			
			if (pManager->returncountoffigrect())
			{
				m = pManager->returncountoffigrect();
				pOut->PrintMessage("Pick rectangles");
				k = 1;


				while (correct < m)
				{


					Point p;
					pIn->GetPointClicked(p.x, p.y);

					CFigure* L = pManager->returnfigonpoint(p);
					if (L == nullptr)
					{
						continue;
					}

					CRectangle* r1 = dynamic_cast<CRectangle*>(L);
					if (r1 != NULL)

					{
						correct++;

					}
					else
					{
						wrong++;
					}
					pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct) + "," + to_string(wrong));
					A = new ActDelete(pManager, L);
					A->Execute();
				}//gets all clicks untill user clicks all correct figs
				pOut->ClearStatusBar();

				pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct) + ", " + to_string(wrong));
				delete this;
				//pOut->ClearStatusBar();
			}
			break;
		case ITM_CIR:
			
			
			if (pManager->returncountoffigcirc())
			{
				m = pManager->returncountoffigcirc();
				pOut->PrintMessage("Pick circles");
				k = 1;



				while (correct < m)
				{


					Point p;
					pIn->GetPointClicked(p.x, p.y);

					CFigure* L = pManager->returnfigonpoint(p);
					if (L == nullptr)
					{
						continue;
					}

					Ccircle* r1 = dynamic_cast<Ccircle*>(L);
					if (r1 != NULL)

					{
						correct++;

					}
					else
					{
						wrong++;
					}
					pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct) + "," + to_string(wrong));
					A = new ActDelete(pManager, L);
					A->Execute();
				}//gets all clicks untill user clicks all correct figs
				pOut->ClearStatusBar();

				pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct) + ", " + to_string(wrong));
				delete this;
				//pOut->ClearStatusBar();
			}
			break;
		case ITM_SQU:
		
			if (pManager->returncountoffigsquare()) {
				m = pManager->returncountoffigsquare();
				pOut->PrintMessage("Pick square"); k = 1;

				
				while (correct < m)
				{


					Point p;
					pIn->GetPointClicked(p.x, p.y);

					CFigure* L = pManager->returnfigonpoint(p);
					if (L == nullptr)
					{
						continue;
					}

					Square* r1 = dynamic_cast<Square*>(L);
					if (r1 != NULL)

					{
						correct++;

					}
					else
					{
						wrong++;
					}
					pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct) + "," + to_string(wrong));
					A = new ActDelete(pManager, L);
					A->Execute();
				}//gets all clicks untill user clicks all correct figs
				pOut->ClearStatusBar();

				pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct) + ", " + to_string(wrong));
				delete this;
				//pOut->ClearStatusBar();
			}
			break;
		case ITM_HEX:

			if (pManager->returncountoffighexagon())
			{
				m = pManager->returncountoffighexagon();
				pOut->PrintMessage("Pick hexa"); k = 1;


				
				while (correct < m)
				{


					Point p;
					pIn->GetPointClicked(p.x, p.y);

					CFigure* L = pManager->returnfigonpoint(p);
					if (L == nullptr)
					{
						continue;
					}

					CHexagon* r1 = dynamic_cast<CHexagon*>(L);
					if (r1 != NULL)

					{
						correct++;

					}
					else
					{
						wrong++;
					}
					pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct) + "," + to_string(wrong));
					A = new ActDelete(pManager, L);
					A->Execute();
				}//gets all clicks untill user clicks all correct figs
				pOut->ClearStatusBar();

				pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct) + ", " + to_string(wrong));
				delete this;
				//pOut->ClearStatusBar();
			}
			break;
		case ITM_TRI:
			
			if (pManager->returncountoffigtriangle())
			{
				m = pManager->returncountoffigtriangle();
				pOut->PrintMessage("Pick triangle");
				
				k = 1;
				
				while (correct < m)
				{


					Point p;
					pIn->GetPointClicked(p.x, p.y);

					CFigure* L = pManager->returnfigonpoint(p);
					if (L == nullptr)
					{
						continue;
					}

					CTriangle* r1 = dynamic_cast<CTriangle*>(L);
					if (r1 != NULL)

					{
						correct++;

					}
					else
					{
						wrong++;
					}
					pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct) + "," + to_string(wrong));
					A = new ActDelete(pManager, L);
					A->Execute();
				}//gets all clicks untill user clicks all correct figs
				pOut->ClearStatusBar();

				pOut->PrintMessage("nom of correct picks,no of wrong picks " + to_string(correct) + ", " + to_string(wrong));
				delete this;
				//pOut->ClearStatusBar();
			}
			
	
		}
	} while (k == 0);
	delete this;
}



