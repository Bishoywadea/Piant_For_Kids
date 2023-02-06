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
	Point P1, P2; //Rectangle Corners
	GfxInfo CircGfxInfo;
	bool Sound;
	CFigure *DeletedFig;
public:
	AddCircle(ApplicationManager* pApp,bool IsEnabled);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool b);
	virtual void AddMeUndo(bool redo);
	virtual void AddMeRec();
	virtual void undo();
	virtual void redo();
};

