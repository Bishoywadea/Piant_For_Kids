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
	GfxInfo SquaGfxInfo;
	bool Sound;
	CFigure *DeletedFig;
public:
	AddSquare(ApplicationManager* pApp, bool IsEnabled);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute(bool read);
	virtual void AddMeUndo(bool redo);
    virtual void undo();
	virtual void redo();
	virtual void AddMeRec();
};

