#pragma once
#include "Actions/Action.h"
#include "fstream"

class LoadAction :public Action
{
private:
	ifstream InputFile;
	string fileName;
public:
	LoadAction(ApplicationManager* pApp);
    void ReadActionParameters();
	virtual void Execute();
	color ConvertStringToColor(string);
};

