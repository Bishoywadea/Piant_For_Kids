#pragma once
#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddCircle.h"
#include "AddHexagon.h"
#include "AddSquare.h"
#include "AddTriangle.h"
#include "Shapesmood.h"
#include"back_icon.h"
#include"SelectAction.h"
#include"MoveAction.h"
#include"ActDelete.h"
#include"Createplaymood.h"
#include"AddColor.h"
#include"Actions/Action.h"
#include "Undo.h"
#include "Redo.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		i=0;
		countre=0;
		countdel=0;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	for(int i=0; i<5; i++)
		Undoarr[i] = NULL;	
	for(int i=0; i<5; i++)
		Redoarr[i] = NULL;	
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
			pAct = new AddColor(this);
			break;

		case ACT_SELECT:
			pAct = new SelectAction(this);
			break;
		case ACT_MOVE:
			pAct = new MoveAction(this);
			break;
		case ACT_DELETE:
			pAct = new ActDelete(this);
			break;
		case ACT_UNDO:
			pAct=new Undo(this);
			break;
		case ACT_REDO:
			pAct=new Redo(this);
			break;
		/*case Undo:
			pAct = new Createplaymood(this);
			break;*/
		/*case ACT_CLEARALL:
			Clearall();
			break;*/
//==================================================================================//
//								drawing shapes section       						//
//==================================================================================//
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_CIRCLE:
			pAct = new AddCircle(this);
			break;
		case DRAW_HEXAGON:
			pAct = new AddHexagon(this);
			break;
		case DRAW_TRIANGLE:
			pAct = new AddTriangle(this);
			break;
		case DRAW_SQUARE:
			pAct = new AddSquare(this);
			break;
		
		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{ 
		
		if(i>4 &&ActType!=ACT_UNDO && ActType!=SHAPES_MENU && ActType!=TO_DRAW && ActType!=ACT_SELECT&&ActType!=ACT_REDO)
			
	{
        int j;
		for (j = 0; j < 4; j++)
		{
			
			Undoarr[j]=Undoarr[j+1];
			
		}
		i=4;
	}
		if(ActType!=ACT_UNDO && ActType!=SHAPES_MENU && ActType!=TO_DRAW && ActType!=ACT_SELECT&&ActType!=ACT_REDO)
	{
		for(int i=0; i<5; i++)
		{
		Redoarr[i] = NULL;	
		}
	Undoarr[i]=pAct;
	i++;
	}
		pAct->Execute();//Execute
		//pAct = NULL;
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
	return 0;
}
void ApplicationManager::Deletefig(CFigure*c)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == c)
		{
			DeletedList[countdel]=FigList[i];
			FigList[i]=NULL;
			delete FigList[i];
			FigList[i] = FigList[FigCount-1];
			countdel++;
			FigCount--;
			break;

		}
	}
}
CFigure* ApplicationManager::Deletelastfig()
{
	if(FigCount>=1)
	{
	CFigure*Deletedfig=FigList[FigCount-1];
	DeletedList[countdel]=Deletedfig;
	countdel++;
	FigList[FigCount-1]=NULL;
	delete FigList[FigCount-1];
	FigCount--;
	return Deletedfig;
	}
	return NULL;
}
void ApplicationManager::ReDraw()
{
	FigCount++;
	AddFigure(DeletedList[countdel-1]);
	countdel--;
}
Action* ApplicationManager::Undof()
{  
	if(i>=1)
	{
	Action*undoact;
	undoact=Undoarr[i-1];
	if(Redoarr[countre]==NULL)
	Redoarr[countre]=undoact;
	else
	{
		countre++;
		Redoarr[countre]=undoact;

	}
	countre++;
	Undoarr[i-1]=NULL;
	delete Undoarr[i-1];
	i--;
	return undoact;
	}
	else 
	{
	return NULL;
	}
	
}
Action* ApplicationManager::Redof()
{
	if(countre>=1)
	{
	Action*redoact;
	redoact=Redoarr[countre-1];
	if(redoact!=NULL)
	{
	if(Undoarr[i]==NULL)
	Undoarr[i]=redoact;
	else
	{
		i++;
		Undoarr[i]=redoact;

	}
    i++;
	Redoarr[countre-1]=NULL;
	delete Redoarr[countre-1];
	countre--;
	return redoact;
	}
	}
	else 
	{
	return NULL;
	}


	}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	
	for(int i=0; i<FigCount; i++)
		if (FigList[i] != NULL)
		{
			FigList[i]->Draw(pOut);
		}//Call Draw function (virtual member fn)
}
void ApplicationManager::Clearall()//when 
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
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
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
