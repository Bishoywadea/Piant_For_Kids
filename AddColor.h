#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "GUI\Input.h"

class AddColor:public Action 
{
private:
	color c;
	int ACT;
	bool Sound;
	CFigure* F;
	CFigure*Wasfilled[5];
	int countfilled;
	int countredo;
public:
	AddColor(ApplicationManager* pApp,bool IsEnabled, int color);
	void ReadActionParameters();//reads which color user wants to use//note you can only choose one colorat a time
	void Execute(bool b);//changes fill color to desired color//SARAH
	virtual void AddMeUndo(bool redo);
	virtual void undo();
	virtual void redo();
	virtual void AddMeRec();
};

