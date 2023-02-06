#pragma once
#include"Actions\Action.h"
class Stop:public Action
{
	bool Sound;
public:
	Stop(ApplicationManager*pApp, bool IsEnabled);
	 void ReadActionParameters();
	 void Execute(bool read);
	virtual void undo();
	virtual void AddMeUndo(bool redo);
	virtual void redo();
	virtual void AddMeRec();
	~Stop();
};

