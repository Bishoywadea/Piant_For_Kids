#pragma once
#include"Actions\Action.h"
class Redo:public Action
{	
	public:
		
	Redo(ApplicationManager*pApp);
	void ReadActionParameters();
	void Execute();
	virtual void undo();
	virtual void redo();
	~Redo();
};

