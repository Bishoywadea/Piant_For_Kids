#pragma once
#include"Actions/Action.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Square.h"

class AddSquare:public Action
{
private:
	Point P1; //Square Center
	CFigure *DeletedFig;
	GfxInfo SquaGfxInfo;
public:
	AddSquare(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute();
    virtual void undo();
	virtual void redo();
};

