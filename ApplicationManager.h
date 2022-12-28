#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include"Actions/Action.h"
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* DeletedList[5];
	CFigure* SelectedFig; //Pointer to the selected figure
	
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	Action*Undoarr[5];
	Action*Redoarr[5];
	CFigure*WasSelected[5];
	int i;
	int countre;
	int countdel;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* Returnselectedfig() const;//function that loops through fig list to find selected figure and returns it, if not found return null
    void Deletefig(CFigure*c);//deletes fig//SARAH
	Action* Undof();
	Action* Redof();
	CFigure* Deletelastfig();
	void ReDraw();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	int getfigcount() const;
	int returnfigcolourcount(color c)const;
	CFigure* returnfigonpoint(Point p);//finds fig within point//sarah
	CFigure** returnfiglist();
	bool ifanyiscolored();

	int returncountoffigrect();

	int returncountoffigcirc();

	int returncountoffighexagon();

	int returncountoffigtriangle();

	int returncountoffigsquare();



};

#endif