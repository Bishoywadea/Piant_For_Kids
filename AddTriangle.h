#pragma once
#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "CTriangle.h"

class AddTriangle:public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo TriGfxInfo;
	bool Sound;
public:
	AddTriangle(ApplicationManager* pApp,bool IsEnabled);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};

