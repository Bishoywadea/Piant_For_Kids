#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
class Shapesmood:public Action
{
public:
	Shapesmood(ApplicationManager* pApp);
	//Execute action (code depends on action type)
	virtual void Execute() ;
	virtual void ReadActionParameters();
};

