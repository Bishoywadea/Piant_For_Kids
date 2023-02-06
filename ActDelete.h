#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Ccircle.h"


class ActDelete:public Action
{
private:
	CFigure* fig;
public:
	ActDelete(ApplicationManager* pApp,CFigure *f=nullptr);
	void ReadActionParameters();
	void Execute();
};

