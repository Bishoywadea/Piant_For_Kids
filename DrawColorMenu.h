#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "GUI\Input.h"

class DrawColorMenu :public Action
{
private:
	color c;
	CFigure* WasHiglighted[5];
	int countHigh;
	int countredo;
public:
	DrawColorMenu(ApplicationManager* pApp);
	void ReadActionParameters();//reads which color user wants to use//note you can only choose one colorat a time
	virtual void Execute(bool read);//changes DRAW color to desired color//SARAH
	virtual void AddMeUndo(bool redo);
	virtual void undo();
	virtual void redo();
	virtual void AddMeRec();
};

