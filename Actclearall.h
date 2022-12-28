#pragma once

#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Ccircle.h"

class Actclearall: public Action
{
public:
	Actclearall(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};

