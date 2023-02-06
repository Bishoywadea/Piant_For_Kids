#pragma once

#include "..\defs.h"
#include "..\GUI\Output.h"
#include<fstream>
//Base class for all figures
class CFigure
{
protected:
	static int ID;		          //Each figure has an ID
	bool Selected;	              //true if the figure is selected.
	GfxInfo FigGfxInfo;	          //Figure graphis info
	Point C0;                     //center before moving
	color FCarr [5];              //Fill color list
	color DCarr [5];              //Draw color list
	int FCcount;                  //Fill color counter
	int DCcount;                  //Draw color counter
public:

	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	virtual ShapesMenuItem Returnshapestype()=0;//returns type of shape in enum
	void undoFC();               //Undoing fill color
	void undoDC();               //Undoing draw color
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual	Point getcenter()=0;                        //returns C0
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual void Save(ofstream& OutFile) = 0;           //function responisble for every figure save its data in the out file //BISHOY
	virtual void Load(ifstream& InFile) = 0;            //Load fig //BISHOY
	void clearcolor();                                  //Clears color before play
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	double CalcDistance(Point A, Point B) const;   //function to calc distance to help in deciding the click on figure or not in functon (IsOnFig) //BISHOY
	virtual void GetTheCorner(Point A)=0;
	virtual void Resize(Point A) = 0;
	virtual bool IsOnFig(int, int)  = 0;      //Checks to deciding the click is on figure or not //BISHOY
    virtual void MOVE(Point p1) = 0;      //function to move figure to point p1 //SARAH
	string ConvertColorToString(color c);          //function to convert color type to string to be able to write them in the out file //BISHOY
	color ConvertStringToColor(string);            //function to convert string type to color to be able to read them from the in file //BISHOY
	bool IsFilled();
	virtual int iffigtype() = 0;//function to return certian figure number in enum
	int getfigcolour();//used in playmood
	color getfigcolorascolor();//used to draw subsequent figs
};

