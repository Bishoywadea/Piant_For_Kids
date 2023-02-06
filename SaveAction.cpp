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
	if (UI.FillColor != UI.BkGrndColor)
	{
		OutFile << DrawColor << "\t" << FillColor << "\n" << Fignumber << endl;
	}
	else
	{
		OutFile << DrawColor << "\t" << "NOCOLOR" << "\n" << Fignumber << endl;
	}
	
}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (SaveName== "UNINITIALIZED.txt")
	{
		pOut->PrintMessage("Enter Save Name");
		SaveName = pIn->GetSrting(pOut) + ".txt";
	}
	pOut->ClearStatusBar();
}

void SaveAction::Execute(bool read)
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
		else
		{
			return "NO COLOR";
		}
}
void SaveAction::undo()
{


}
void SaveAction::redo()
{

}
void SaveAction::AddMeUndo(bool redo)
{


}
void SaveAction::AddMeRec()
{

	
}



