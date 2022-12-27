#pragma once
#include"Actions\Action.h"
class Undo :public Action
{
public:
	Undo(ApplicationManager*pApp);
	 void ReadActionParameters();
	 void Execute();
	virtual void undo();
	virtual void redo();
	~Undo();
};

