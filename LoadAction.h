#pragma once
#include "Actions/Action.h"
#include "fstream"

class LoadAction :public Action
{
private:
	ifstream InputFile;
	string fileName;
public:
	LoadAction(ApplicationManager* pApp,string s="UNINITIALIZED");
    void ReadActionParameters();
	virtual void Execute(bool read) ;
	color ConvertStringToColor(string);
	virtual void AddMeUndo(bool redo);
	virtual void undo();
	virtual void redo();
	virtual void AddMeRec();
};


