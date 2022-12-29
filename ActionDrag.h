#pragma once
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"Actions/Action.h"
#include<iostream>
class ActionDrag :public Action
{
	button btn;
	buttonstate stat;
	Point P;
	CFigure* SelectedFig;
public:
	ActionDrag(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();
};

