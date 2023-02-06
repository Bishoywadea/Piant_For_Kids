#pragma once
#include"Actions\Action.h"
class Redo:public Action
{	
	bool Sound;
	public:
		
	Redo(ApplicationManager*pApp, bool IsEnabled);
	void ReadActionParameters();
	void Execute(bool read);
	virtual void AddMeUndo(bool redo);
	virtual void undo();
	virtual void redo();
	virtual void AddMeRec();
	~Redo();
};

