#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"
#include<fstream>
class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	int pvid;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Draw(Output* pOut) const;
	void PrintInfo(Output* pOut);
	bool IsOnFig(int x, int y) const;
	ShapesMenuItem Returnshapestype();//returns type of shape in enum
	void MOVE(Point p1);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
};

#endif