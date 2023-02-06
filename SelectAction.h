#include "Actions/Action.h"
#include "Figures/CFigure.h"

class SelectAction : public Action {
private:
	bool Sound;
	Point P;  //Clicked point
	CFigure* SelectedFig; //Clicked figure (NULL if no figure is clicked)
public:
	SelectAction(ApplicationManager* pApp,bool IsEnabled);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute(bool b);
	void Selected();
	void AddMeUndo(bool redo);
	void Unselected();
	virtual void undo();
	virtual void redo();
	virtual void AddMeRec();
};


