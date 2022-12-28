#pragma once
#include"Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include"Figures/CFigure.h"
#include"Figures/CRectangle.h"


class MoveAction :public Action
{
private:
	CFigure* Fig;
	Point p1;
	Point unp1;
	
public:
	MoveAction(ApplicationManager* pApp);
	void ReadActionParameters();//creates point where we want to move fig and stores in p1
	void Execute();//excutes the moving
	virtual void undo();
    virtual void redo();

};

