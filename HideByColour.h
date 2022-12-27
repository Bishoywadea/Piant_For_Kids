
#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include<cstdlib>
#include"AddColor.h"

class HideByColour:public Action
{
	color c;
	Action* A;
	static int i;
public:
	HideByColour(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~HideByColour();
};

