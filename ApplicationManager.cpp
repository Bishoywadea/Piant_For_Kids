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
#include "MoveAction.h"
#include "ActDelete.h"
#include "Createplaymood.h"
#include "AddColor.h"
#include "DrawColour.h"
#include "Actclearall.h"
#include "ActSound.h"
#include"SaveAction.h"
#include"LoadAction.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	IsEnabled = 1;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
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
			pAct = new AddColor(this, IsEnabled);
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

		case TO_PLAY:
			pAct = new Createplaymood(this);
			break;
		case ACT_CLEARALL:
			pAct = new Actclearall(this);
			break;
		case ACT_CHNGDRAWCOLOUR:
			pAct = new DrawColour(this);
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
		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
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
CFigure* ApplicationManager::returnfigonpoint(Point p)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsOnFig(p.x, p.y))
			return FigList[i];
	}
	return nullptr;
}

CFigure** ApplicationManager::returnfiglist()
{
	return FigList;
	
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
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}