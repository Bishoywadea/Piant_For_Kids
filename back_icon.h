#pragma once
#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
class Backicon:public Action
{
public:
	Backicon(ApplicationManager* pApp);
	//Execute action (code depends on action type)
	virtual void Execute(bool b);
	virtual void ReadActionParameters();
	virtual void AddMeUndo(bool redo);
	virtual void undo();
	virtual void redo();
	virtual void AddMeRec();
};

