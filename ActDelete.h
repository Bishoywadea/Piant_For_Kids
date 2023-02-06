#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Ccircle.h"


class ActDelete:public Action
{	
	CFigure *DeletedFig;
	bool Sound;
public:
	ActDelete(ApplicationManager* pApp, bool IsEnabled);
	void ReadActionParameters();
	void Execute(bool read);
	virtual void AddMeUndo(bool redo);     //Adds actions to undoarr array
	virtual void undo();
	virtual void redo();
	virtual void AddMeRec();               //Adds actions to recordact array
};

