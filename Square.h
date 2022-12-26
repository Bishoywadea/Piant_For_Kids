#pragma once
#include "Figures/CFigure.h"
class Square :
    public CFigure
{
private:

	Point Center;
	Point UpperLeft;
	Point LowerRight;
	int pvid;
public:
	Square(Point, GfxInfo FigureGfxInfo);
	Square();
	virtual void Draw(Output* pOut) const;
	void PrintInfo(Output* pOut);
	virtual bool IsOnFig(int x, int y) const;
	ShapesMenuItem Returnshapestype();//returns type of shape in enum
	void MOVE(Point );

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
};



