#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Ccircle.h"

class AddCircle :
    public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo CircGfxInfo;
public:
	AddCircle(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};
