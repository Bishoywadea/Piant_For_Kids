#include "LoadAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/output.h"
#include "Figures/CRectangle.h"
#include "Ccircle.h"
#include "Square.h"
#include "CTriangle.h"
#include "CHexagon.h"
#include "Actclearall.h"

LoadAction::LoadAction(ApplicationManager* pApp,string s) :Action(pApp)
{
	fileName = s+".txt";
}



//Read Parameters for the load action
void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (fileName == "UNINITIALIZED.txt")
	{
		pOut->PrintMessage("Enter the name of the file you want to load");


		fileName = pIn->GetSrting(pOut) + ".txt";
	
	
	InputFile.open(fileName);
	pOut->ClearDrawArea();
	pManager->clearundo();
	pManager->clearredo();
	//check if the file doesnot exists
	if (InputFile.is_open())
	{
		pOut->PrintMessage("Your file has been successfully loaded");
	}
	else { pOut->PrintMessage("No file found with name: " + fileName);
	}
	}
	else
	{

	InputFile.open(fileName);
	pOut->ClearDrawArea();
	//check if the file doesnot exists
	if (InputFile.is_open())
	{
		pOut->PrintMessage("Play More!!");
	}
	else { pOut->PrintMessage("Error" + fileName);
	}
	}
}

//Execute action Load Action
void LoadAction::Execute(bool read)
{
	ReadActionParameters();
	
	//check if the file is opened first
	if (InputFile.is_open())
	{
		//read from the file the current draw clr & fill clr &number of figuers 
		CFigure* pFig = NULL;
		string shapeType;
		int numberOfFiguers;
		string DrawClr;
		InputFile >> DrawClr;
		UI.DrawColor = ConvertStringToColor(DrawClr);
		string FillClr;
		InputFile >> FillClr;
		UI.FillColor = ConvertStringToColor(FillClr);
		InputFile >> numberOfFiguers;
		//cleaning the figlist before loading the file
		pManager->Clearall();
		// Loop all figures ,identify the type ,then create an obj of the specified type,add to the figlist  after the loading it
		for (int i = 0; i < numberOfFiguers; i++)
		{
			InputFile >> shapeType;
			if (shapeType == "Circle")
			{
				pFig = new Ccircle;
			}
			
			else if (shapeType == "HEXAGON")
			{
				pFig = new CHexagon;
			}

			else if (shapeType == "RECTANGLE")
			{
				pFig = new CRectangle;
			}

			else if (shapeType == "TRIANGLE")
			{
				pFig = new CTriangle;
			}

			else if (shapeType == "SQUARE")
			{
				pFig = new Square;
			}
		
			pFig->Load(InputFile);
			if (pFig != NULL)
			{
				//seneding it to the application manager to add them
				pManager->AddFigure(pFig);
			}
		}
		//close the file after looping 
		InputFile.close();
	}
}
//function that get a string clr name returning a clr obj
color LoadAction::ConvertStringToColor(string name)
{
	if (name == "RED")
	{
		return RED;
	}

	else if (name == "BLACK")
	{
		return BLACK;
	}

	else if (name == "BLUE")
	{
		return BLUE;
	}

	else if (name == "GREEN")
	{
		return GREEN;
	}

	else if (name == "ORANGE")
	{
		return ORANGE;
	}
	
	else if (name == "YELLOW")
	{
		return YELLOW;
	}

	else
	{
		return UI.BkGrndColor;
	}
}
void LoadAction::undo()
{

}
void LoadAction::redo()
{
	
	
}
void LoadAction::AddMeUndo(bool redo)
{


}
void LoadAction::AddMeRec()
{
	

}