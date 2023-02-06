#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include<cstdlib>
#include"AddColor.h"
#include "HideByColour.h"
#include"SaveAction.h"
#include "LoadAction.h"
#include"Figures/CRectangle.h"
#include"AddCircle.h"
#include"AddHexagon.h"
#include"AddSquare.h"
#include"AddTriangle.h"
#include"ACTHIDE.h"
#include"ActDelete.h"
#include<random>
class HideByshapes :public Action
{

	Action* A;
	int figcounter;
	int figitems;
public:
	HideByshapes(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool b=1);
	virtual void AddMeUndo(bool redo);
	virtual void AddMeRec();
	virtual void undo();
	virtual void redo();
	
};



