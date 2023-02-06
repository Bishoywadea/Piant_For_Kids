#include "ACTHIDE.h"
#include <time.h>;
int ACTHIDE::i = 0;
ACTHIDE::ACTHIDE(ApplicationManager* pApp)
{
	pManager = pApp;
	srand(time(NULL));
	i = rand();
    SaveAction s(pManager, pManager->getfigcount(), to_string(i));
	s.Execute(1);

	//s.Execute(1);
	pManager->UpdateInterface();
}
void ACTHIDE::undo()
{

}
void ACTHIDE::redo()
{

}
void ACTHIDE::AddMeUndo()
{


}
void ACTHIDE::AddMeRec()
{
	

}

















ACTHIDE::~ACTHIDE()
{
	LoadAction l(pManager,to_string(i));
	l.Execute(1);
	pManager->UpdateInterface();
	
	
}
