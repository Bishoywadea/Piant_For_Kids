#pragma once
#include"Actions\Action.h"
class Play_Rec:public Action
{
	bool Sound;
public:
	Play_Rec(ApplicationManager*pApp,bool IsEnabled);
	void ReadActionParameters();
    void Execute(bool b);
	virtual void AddMeUndo(bool redo);
	virtual void undo();
	virtual void redo();
	virtual void AddMeRec();
	~Play_Rec();
};

