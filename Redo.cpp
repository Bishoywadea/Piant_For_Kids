#include "Redo.h"
#include"Actions/Action.h"
#include"ApplicationManager.h"

Redo::Redo(ApplicationManager*pApp):Action(pApp)
{

}
void Redo::ReadActionParameters()
{


}
void Redo::Execute()
{   pManager->GetOutput()->PrintMessage("Redo icon");
Action* ptr=pManager->Redof();
if(ptr!=NULL){
	ptr->redo();}
else
	 pManager->GetOutput()->PrintMessage("No Actions done to redo");
}
void Redo::undo()
{


}
void Redo::redo()
{


}
Redo::~Redo()
{
}
