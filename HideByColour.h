
#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include<cstdlib>
#include"AddColor.h"


class HideByColour:public Action
{
	color c;
	Action* A;
	static int i;

#include "HideByColour.h"
#include"SaveAction.h"
#include "LoadAction.h"
#include"ActDelete.h"
#include<random>
#include"ACTHIDE.h"
class HideByColour:public ACTHIDE
{
	color c;
	Action* A;


public:
	HideByColour(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();

	~HideByColour();

};

