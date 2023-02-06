#pragma once

#include"SaveAction.h"
#include "LoadAction.h"
#include"ActDelete.h"
#include"Actions/Action.h"
#include<random>
#include"ACTHIDE.h"
class HideByColour:public Action
{
	color c;
	Action* A;


public:
	HideByColour(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool b=1);
	virtual void AddMeUndo(bool redo);
	virtual void AddMeRec();
	virtual void undo() ;
	virtual void redo() ;


};

