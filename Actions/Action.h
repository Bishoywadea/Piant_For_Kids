#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute(bool b) =0;
	virtual void AddMeUndo(bool redo)=0;
	virtual void AddMeRec()=0;
	virtual void undo()=0;
    virtual void redo()=0;
	const string turnenumshapesintostring(int);
	const string turnenumcolorsintostring(int);

};

#endif