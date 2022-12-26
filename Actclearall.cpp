#include "Actclearall.h"
Actclearall::Actclearall(ApplicationManager* pApp):Action(pApp)
{
	
}
void Actclearall::ReadActionParameters()
{
}
void Actclearall::Execute()
{
	int FigCount = pManager->getfigcount();
	CFigure** FigList = pManager->returnfiglist();
		for (int i = 0; i < FigCount; i++)
		{
			delete FigList[i];
			FigList[i] = NULL;
		}
		FigCount = 0;

}
