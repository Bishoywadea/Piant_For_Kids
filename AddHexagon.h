
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
	CFigure *DeletedFig;
public:
	AddHexagon(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void undo();
	virtual void redo();

};

