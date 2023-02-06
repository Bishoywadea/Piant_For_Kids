#include "Record.h"
#include"Actions/Action.h"
#include"ApplicationManager.h"
#include"Actions\Action.h"
Record::Record(ApplicationManager*pApp, bool IsEnabled):Action(pApp)
{
	Sound = IsEnabled;

}
void Record::ReadActionParameters()
{


}
void Record::Execute(bool read)
{
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\start.wav"), NULL, SND_ASYNC);
	}
	pManager->GetOutput()->PrintMessage("Start Recording icon");
	if(pManager->getfigcount()==0)
	pManager->recording();
	else
		pManager->GetOutput()->PrintMessage("Can't Record");

}
void Record::undo()
{


}
void Record::redo()
{


}
void Record::AddMeUndo(bool redo)
{


}
Record::~Record(void)
{
}
void Record::AddMeRec()
{


}