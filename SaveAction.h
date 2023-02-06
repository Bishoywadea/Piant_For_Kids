#pragma once
#include<fstream>
#include"Actions/Action.h"

class SaveAction :public Action
{
	int Fignumber;
	string DrawColor;
	string FillColor;
	string SaveName;
	ofstream OutFile;
public:
	SaveAction(ApplicationManager* pApp,int number,string s="UNINITIALIZED");
	void Heading(int number);
	void ReadActionParameters();
	void Execute(bool b);
	string ConvertColorToString(color c);
	virtual void AddMeUndo(bool redo);
    virtual	void undo();
	virtual void redo();
	virtual void AddMeRec();
};

