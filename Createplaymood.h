#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "CHexagon.h"
class Createplaymood:public Action
{
public:
	Createplaymood(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool b);///create the playmood toolbar//SARAH
	virtual void AddMeUndo(bool redo);
    virtual	void undo();
	virtual void redo();
	virtual void AddMeRec();

};

