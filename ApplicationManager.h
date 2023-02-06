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
	bool IsEnabled;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	Action*Undoarr[5];                
	Action*Redoarr[5];                
	Action*Recordact[20];
	Action*LastAct;
	int countundo;
	int countre;
	int countrecord;
	bool recflag;                 //Flag to start or stop recording
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
	int getfigcount() const;                     //Returns figure count in figlist
    void Deletefig(CFigure*c);//deletes fig//SARAH
	void SaveAll(ofstream& OutFile); //function to loop on the fig list and call save function of every element in it //BISHOY
	void DeleteFigList();            //function do delete all fig list to be used in load action
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void AddToUndo(Action*act,bool clrredo);     //Adds actions to undoarr 
	                                             // clrredo to clear redo array if any new actions are done and avoid clearing if the action was redo
	void AddToRedo();           //Adds actions from undo to redo
	void AddToRec(Action*act);  //Adds actions to Recordact array
	void PlayRec();             //Excutes records in Recordact
	Action* GetLastUndo();      //Gets last action in undo list
	Action* GetLastRedo();      //Gets last action in redo list
	CFigure* Deletelastfig();   //Deletes the last figure in figlist
	void recording();           //Sets recflag to true
	void stop_rec();            //Sets recflag to false        
	void Clearall();//prototype of claer all func, add undo and redo as stated in phase 1 //SARAH
	int returnfigcolourcount(int);//finds number of figures of certain  color
	int returnfigsofcertaintypeandcolor(int color1, int figtype);
	int getcertainfigcount(int figtype);
	void clearundo();
	void clearredo();
	void clearrecordings();
};

#endif