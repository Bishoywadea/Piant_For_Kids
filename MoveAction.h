#pragma once
#include"Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include"Figures/CFigure.h"
#include"Figures/CRectangle.h"


class MoveAction :public Action
{
	bool Sound;
private:
	CFigure* Fig;
	Point p1;
	Point unp1;
	
public:
	MoveAction(ApplicationManager* pApp, bool IsEnabled);
	void ReadActionParameters();//creates point where we want to move fig and stores in p1
	void Execute(bool read);//excutes the moving
	virtual void AddMeUndo(bool redo);
	virtual void undo();
    virtual void redo();
	virtual void AddMeRec();
};

