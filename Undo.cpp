#include "Undo.h"
#include"Actions/Action.h"
#include"ApplicationManager.h"
Undo::Undo(ApplicationManager*pApp):Action(pApp)
{

}
void Undo::ReadActionParameters()
{


}

void Undo::Execute()
{   pManager->GetOutput()->PrintMessage("Undo icon");
Action* ptr=pManager->Undof();
if(ptr!=NULL){
	ptr->undo();}
else
	 pManager->GetOutput()->PrintMessage("No Actions done to undo");
}
void Undo::undo()
{

}
void Undo::redo()
{

}
Undo::~Undo()
{
}
