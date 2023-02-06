#pragma once
#include"ApplicationManager.h"
#include"Actions/Action.h"
#include"SaveAction.h"
#include"LoadAction.h"
#include<random>
class ACTHIDE
{

    public:

	ApplicationManager* pManager;
	static int i;
	ACTHIDE(ApplicationManager* pApp);
	virtual void undo();
	virtual void AddMeUndo();
	virtual void AddMeRec();
	virtual void redo();
	~ACTHIDE();
};

