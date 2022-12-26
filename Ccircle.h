#pragma once
#include "Figures/CFigure.h"
class Ccircle :public CFigure
{
private:
	Point Center;
	Point Radius;
    int radius; //added to be used in IsOnFig function //BISHOY
	int pvid;
public:
	 Ccircle(Point, Point, GfxInfo FigureGfxInfo);
	 Ccircle();
	 void Draw(Output* pOut) const;
	 void PrintInfo(Output* pOut);
	 bool IsOnFig(int x, int y) const; //Checks to deciding the click is on figure or not //BISHOY
	 void MOVE(Point p);//Moves fig
	 ShapesMenuItem Returnshapestype() ;//returns type of shape in enum
	 virtual void Save(ofstream& OutFile);
	 virtual void Load(ifstream& InFile);
};
