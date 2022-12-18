#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Ccircle.h"

class AddColor:public Action 
{
private:
	color c;
public:
	AddColor(ApplicationManager* pApp);
	void ReadActionParameters();//reads which color user wants to use//note you can only choose one colorat a time
	void Execute();//changes fill color to desired color//SARAH
};

