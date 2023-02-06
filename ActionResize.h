#pragma once
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"Actions/Action.h"


class ActionResize :public Action
{
	button btn;
	bool flag;
	buttonstate stat;
	Point P;
	CFigure* SelectedFig;
public:
	ActionResize(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Executes the select action
	void Execute(bool b);
	virtual void AddMeUndo(bool redo);
	virtual void undo();
	virtual void redo();
	virtual void AddMeRec();
};