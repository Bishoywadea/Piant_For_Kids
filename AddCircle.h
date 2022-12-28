#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Ccircle.h"

class AddCircle :
    public Action
{
private:
	Point P1, P2; //Circle center and a point 
	GfxInfo CircGfxInfo;
	CFigure *DeletedFig;
public:
	AddCircle(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void undo();
	virtual void redo();

};

