
#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Ccircle.h"

class Actclearall: public Action
{
public:
	Actclearall(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool b=1);
	virtual void AddMeUndo(bool redo);
	virtual void AddMeRec();
	virtual void undo();
	virtual void redo();

};

