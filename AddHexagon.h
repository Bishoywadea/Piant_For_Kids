
#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "AddCircle.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "CHexagon.h"

class AddHexagon :public Action
{
	Point p1;
	GfxInfo HexGfxInfo;
	bool Sound;
public:
	AddHexagon(ApplicationManager* pApp,bool IsEnabled);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

