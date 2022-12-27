#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "GUI\Input.h"

class AddColor:public Action 
{
private:
	color c;
	bool Sound;
public:
	AddColor(ApplicationManager* pApp,bool IsEnabled);
	void ReadActionParameters();//reads which color user wants to use//note you can only choose one colorat a time
	void Execute();//changes fill color to desired color//SARAH
};

