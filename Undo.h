#pragma once
#include"Actions\Action.h"
class Undo :public Action
{
	bool Sound;
public:
	Undo(ApplicationManager*pApp, bool IsEnabled);
    void ReadActionParameters();
	void Execute(bool read);
	virtual void undo();
	virtual void AddMeUndo(bool redo);
	virtual void AddMeRec();
	virtual void redo();
	~Undo();
};

