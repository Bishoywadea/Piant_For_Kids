#pragma once
#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddCircle.h"
#include "AddHexagon.h"
#include "AddSquare.h"
#include "AddTriangle.h"
#include "Shapesmood.h"
#include "back_icon.h"
#include "SelectAction.h"
#include "ActHideByshapes.h"
#include "HideByColour.h"
#include "HideShapesAndColors.h"
#include "MoveAction.h"
#include "ActDelete.h"
#include "Createplaymood.h"
#include "AddColor.h"
#include "DrawColour.h"
#include "ActSound.h"
#include "SaveAction.h"
#include "LoadAction.h"
#include "ActionDrag.h"
#include "ActionResize.h"
#include "Undo.h"
#include "Redo.h"
#include "Record.h"
#include "Stop.h"
#include "Play_Rec.h"
#include "FillColorMenu.h"
#include "DrawColorMenu.h"
#include "Actclearall.h"
#include "Exit.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
    countundo=0;
    countre=0;
    countrecord=0;
	recflag=false;
	FigCount = 0;
	LastAct=NULL;
	IsEnabled = 1;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	for(int i=0; i<5; i++)
		Undoarr[i] = NULL;	
	for(int i=0; i<5; i++)
		Redoarr[i] = NULL;	
	for (int i = 0; i < 20; i++)
		Recordact[i]=NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
//==================================================================================//
//								tool bar actions sections      						//
//==================================================================================//
		case SHAPES_MENU:
			pAct = new Shapesmood(this);
			break;

		case TO_DRAW:
			pAct = new Backicon(this);
			break;

		case COLOUR_MENU:
			pAct = new FillColorMenu(this);
			break;

		case ACT_SELECT:
			pAct = new SelectAction(this, IsEnabled);
			break;

		case ACT_MOVE:
			pAct = new MoveAction(this,IsEnabled);
			break;

		case ACT_DELETE:
			pAct = new ActDelete(this,IsEnabled);
			break;
			case ACT_UNDO:
			pAct=new Undo(this,IsEnabled);
			break;
		case ACT_REDO:
			pAct=new Redo(this, IsEnabled);
			break;
		case ACT_RECORD:
			pAct=new Record(this,IsEnabled);
			break;
		case ACT_STOP:
			pAct=new Stop(this, IsEnabled);
			break;
		case ACT_PLAY:
	
			pAct=new Play_Rec(this,IsEnabled);
			break;
		
		case TO_PLAY:
			pAct = new Createplaymood(this);
			break;
		case ACT_CHNGDRAWCOLOUR:
			pAct = new DrawColorMenu(this);
			break;
		case HIDE_SHAPES:
			pAct = new HideByshapes(this);
			break;
		case HIDE_COLOURS:
			pAct = new HideByColour(this);
			break;
		case HIDE_SHAPSANDCOLOURS:
			pAct = new HideShapesAndColors(this);
			break;

		case Sound :
			pAct = new ActSound(this, &IsEnabled);
			break;

		case ACT_SAVE:
			pAct = new SaveAction(this,FigCount);
			break;

		case ACT_LOAD:
			pAct = new LoadAction(this);
			break;

		case Drag:
			pAct = new ActionDrag(this);
			break;

		case Resize:
			pAct = new ActionResize(this);
			break;
		case ACT_CLEARALL:
			pAct = new Actclearall(this);
			break;

//==================================================================================//
//								drawing shapes section       						//
//==================================================================================//
		case DRAW_RECT:
			pAct = new AddRectAction(this, IsEnabled);
			break;
		case DRAW_CIRCLE:
			pAct = new AddCircle(this, IsEnabled);
			break;
		case DRAW_HEXAGON:
			pAct = new AddHexagon(this, IsEnabled);
			break;
		case DRAW_TRIANGLE:
			pAct = new AddTriangle(this, IsEnabled);
			break;
		case DRAW_SQUARE:
			pAct = new AddSquare(this,IsEnabled);
			break;

//==================================================================================//
//								Fill Coloring shapes section       						//
//==================================================================================//
		case ACT_RED:
			pAct = new AddColor(this, IsEnabled, 0);
			break;

		case ACT_BLUE:
			pAct = new AddColor(this, IsEnabled, 1);
			break;

		case ACT_BLACK:
			pAct = new AddColor(this, IsEnabled, 2);
			break;

		case ACT_GREEN:
			pAct = new AddColor(this, IsEnabled, 3);
			break;

		case ACT_ORANGE:
			pAct = new AddColor(this, IsEnabled, 4);
			break;

		case ACT_YELLOW:
			pAct = new AddColor(this, IsEnabled, 5);
			break;
//==================================================================================//
//								Fill Coloring shapes section       				    //
//==================================================================================//
		case ACT_RED_D:
			pAct = new DrawColour(this, IsEnabled, 0);
			break;

		case ACT_BLUE_D:
			pAct = new DrawColour(this, IsEnabled, 1);
			break;

		case ACT_BLACK_D:
			pAct = new DrawColour(this, IsEnabled, 2);
			break;

		case ACT_GREEN_D:
			pAct = new DrawColour(this, IsEnabled, 3);
			break;

		case ACT_ORANGE_D:
			pAct = new DrawColour(this, IsEnabled, 4);
			break;

		case ACT_YELLOW_D:
			pAct = new DrawColour(this, IsEnabled, 5);
			break;

		case EXIT:
			///create ExitAction here
			pAct = new Exit(this, IsEnabled);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
	    pAct->AddMeUndo(1);
		pAct->AddMeRec();
		pAct->Execute(1);//Execute
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = FigCount - 1; i >= 0; i--) 
	{
		if (FigList[i]->IsOnFig(x, y))
			return FigList[i];
	}
	return NULL;
}

CFigure* ApplicationManager::Returnselectedfig() const
{
	bool f=0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			f = 1;
			return FigList[i];
		}
	}
	if (!f)
	{
		return NULL;
	}
	return NULL;
}

void ApplicationManager::Deletefig(CFigure*c)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == c)
		{
			FigList[i]=NULL;
			delete FigList[i];
			FigList[i] = FigList[FigCount-1];
			FigCount--;
			break;

		}
	}
}
void ApplicationManager::SaveAll(ofstream& OutFile)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save( OutFile);
	}
}
void ApplicationManager::DeleteFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}
void ApplicationManager::AddToUndo(Action*act,bool clrredo)
{
	if(clrredo)
		clearredo();
	if(countundo>4)
	{
	int j;
	for (j = 0; j < 4; j++)   //Overwriting Undoarr to make it always have the last five actions 
	{	
	Undoarr[j]=Undoarr[j+1];		
	}
	countundo=4;
	}
    Undoarr[countundo++]=act;
	
}

Action* ApplicationManager::GetLastUndo()
{
	if(countundo>=1)
	{
	LastAct=Undoarr[countundo-1];
	Undoarr[countundo-1]=NULL;
	delete Undoarr[countundo-1];
	return LastAct;
	}
	return NULL;
}
void ApplicationManager::AddToRedo()
{
	Redoarr[countre]=LastAct;
	countundo--;
	countre++;
}
Action* ApplicationManager::GetLastRedo()
{
	if(countre>=1)
	{
		LastAct=Redoarr[countre-1];
		Redoarr[countre-1]=NULL;
	    delete Redoarr[countre-1];
		countre--;
		return LastAct;
	}
	return NULL;
}
void ApplicationManager::AddToRec(Action*act)         
{
	if(recflag==true &&countrecord<20)
	{
	Recordact[countrecord]=act;
	countrecord++;
	}
	else
	{
	pOut->PrintMessage("Can't record!!!");
	stop_rec();
	}
}
void ApplicationManager::PlayRec()
{
	if(Recordact[0]!=NULL)
	{
	Clearall();
	Sleep(1000);
	for (int i = 0; i < countrecord; i++)
	{
		Recordact[i]->AddMeUndo(1);
		Recordact[i]->Execute(0);
		UpdateInterface();
		if(i%2!=0)
		Sleep(1000);
	}
	pOut->PrintMessage("All recorded actions have been played successfully");
	}
	else
		pOut->PrintMessage("NO ACTIONS RECORDED!!");
}
CFigure* ApplicationManager::Deletelastfig()
{
	if(FigCount>=1)
	{
	CFigure*Deletedfig=FigList[FigCount-1];
	FigList[FigCount-1]=NULL;
	delete FigList[FigCount-1];
	FigCount--;
	return Deletedfig;
	}
	return NULL;
}
void ApplicationManager::recording()
	{
		recflag=true;
	}
void ApplicationManager::stop_rec()
{
	recflag=false;

}
void ApplicationManager::clearrecordings()
{
	for (int i = 0; i < countrecord; i++)
	{
		Recordact[i]=NULL;
		delete Recordact[i];
	}
	countrecord=0;
}
void ApplicationManager::clearredo()
{
	for (int i = 0; i < countre; i++)
	{
		Redoarr[i]=NULL;
		delete Redoarr[i];
	}
	countre-0;
}
void ApplicationManager::clearundo()
{
	for (int i = 0; i < countrecord; i++)
	{
		Undoarr[i]=NULL;
		delete Undoarr[i];
	}
	countundo=0;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	for (int i = 0; i < FigCount; i++)
		if (FigList[i] != NULL)
		{
			FigList[i]->Draw(pOut);
		}//Call Draw function (virtual member fn)
}

int ApplicationManager::getfigcount() const
{
	return FigCount;
}



void ApplicationManager::Clearall()
{

	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->SetSelected(false);          
		FigList[i]->clearcolor();
		FigList[i]=NULL;
		delete FigList[i];
	}
	    UpdateInterface();
	    FigCount = 0;
		pOut->ClearDrawArea();
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < countrecord; i++)
	  delete Recordact[i];
	for (int i = 0; i < FigCount; i++)
	  delete FigList[i];
	delete pIn;
	delete pOut;
}
int ApplicationManager::getcertainfigcount(int figtype)//loop to find nom of certain figure
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		int n = FigList[i]->iffigtype();
		if (n == figtype)
			count++;
	}
	return count;
}
int ApplicationManager::returnfigcolourcount(int col)
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsFilled())
		{
			if (FigList[i]->getfigcolour() == col)
				count++;
		}
	}
	return count;
}

int ApplicationManager::returnfigsofcertaintypeandcolor(int color1, int figtype)
{
	int c1 = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->iffigtype() == figtype && FigList[i]->getfigcolour() == color1)
		{
			c1++;
		}
	}
	return c1;
}