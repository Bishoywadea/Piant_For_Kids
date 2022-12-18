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
	
public:
	MoveAction(ApplicationManager* pApp);
	void ReadActionParameters();//creads point where we want to move fig and stores in p1
	void Execute();//excutes the moving

};

