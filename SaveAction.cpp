#include "SaveAction.h"
#include"ApplicationManager.h"
#include<fstream>

SaveAction::SaveAction(ApplicationManager* pApp, int FigCount):Action(pApp)
{
	Fignumber = FigCount;
}

void SaveAction::Heading(int number)
{
	int numberOfFiguers = number;
	DrawColor = ConvertColorToString(UI.DrawColor);
	FillColor = ConvertColorToString(UI.FillColor);
	OutFile << DrawColor << "\t" << FillColor << "\n" << Fignumber<<endl;
}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter Save Name");
	SaveName = pIn->GetSrting(pOut) + ".txt";
	OutFile.open(SaveName);
	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();
	Heading(Fignumber);
	pManager->SaveAll(OutFile);
	OutFile.close();
}

string SaveAction::ConvertColorToString(color c)
{
		if (c == RED)
		{
			return "RED";
		}
		else if (c == BLACK)
		{
			return "BLACK";
		}
		else if (c == BLUE)
		{
			return "BLUE";
		}
		else if (c == GREEN)
		{
			return "GREEN";
		}
		else if (c == ORANGE)
		{
			return "ORANGE";
		}
		else if (c == YELLOW)
		{
			return "YELLOW";
		}
		else
		{
			return "NO COLOR";
		}
}


