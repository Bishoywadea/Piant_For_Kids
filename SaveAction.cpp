#include "SaveAction.h"
#include"ApplicationManager.h"

SaveAction::SaveAction(ApplicationManager* pApp,int number,string s):Action(pApp)
{
	

	SaveName = s+".txt";

	Fignumber = number;
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



	if (SaveName == "UNinitializedno.txt")

	{
		Input* pIn = pManager->GetInput();

		pOut->PrintMessage("Enter Save Name");
		SaveName = pIn->GetSrting(pOut) + ".txt";
	}
	

	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter Save Name");
	SaveName = pIn->GetSrting(pOut) + ".txt";

	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();
	OutFile.open(SaveName);
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
		else if (c == BEIGE)
		{
			return "BEIGE";
		}
		else
		{
			return "NO COLOR";
		}
}


