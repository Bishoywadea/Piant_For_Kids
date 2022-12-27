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
	virtual void Execute();

	~ActSound();
};

