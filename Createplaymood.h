#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "CHexagon.h"
class Createplaymood:public Action
{
public:
	Createplaymood(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();///create the playmood toolbar//SARAH

};

