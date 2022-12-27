#pragma once

#include "..\defs.h"
#include "..\GUI\Output.h"
#include<fstream>
//Base class for all figures
class CFigure
{
protected:
	static int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	/// Add more parameters if needed.

public:
	color getfigcolour();
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	virtual ShapesMenuItem Returnshapestype()=0;//returns type of shape in enum

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual void Save(ofstream& OutFile) = 0;            //function responisble for every figure save its data in the out file //BISHOY
	virtual void Load(ifstream& InFile) = 0;            //Load fig //BISHOY
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	
	double CalcDistance(Point A, Point B) const;   //function to calc distance to help in deciding the click on figure or not in functon (IsOnFig) //BISHOY
	virtual bool IsOnFig(int, int) const = 0;      //Checks to deciding the click is on figure or not //BISHOY
    virtual void MOVE(Point p1) = 0;               //function to move figure to point p1 //SARAH
	string ConvertColorToString(color c);          //function to convert color type to string to be able to write them in the out file //BISHOY
	color ConvertStringToColor(string);            //function to convert string type to color to be able to read them from the in file //BISHOY
	
};

