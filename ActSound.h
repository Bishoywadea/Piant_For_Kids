#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class ActSound : public Action
{
	bool* IsEnabled;
	ActionType PACT;
public:
	ActSound(ApplicationManager* pApp, bool*);

	virtual void ReadActionParameters();
	void Execute(bool read);
	virtual void AddMeUndo(bool redo);
	virtual void undo();
    virtual void redo();
	virtual void AddMeRec();
	~ActSound();
};

