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
	SaveAction(ApplicationManager* pApp,int FigCount);
	void Heading(int number);
	void SaveAction::ReadActionParameters();
	virtual void Execute();
	string ConvertColorToString(color c);
};

