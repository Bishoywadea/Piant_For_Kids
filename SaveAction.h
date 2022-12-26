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
	SaveAction(ApplicationManager* pApp,int number);
	void Heading(int number);
	void ReadActionParameters();
	virtual void Execute();
	string ConvertColorToString(color c);
};

