#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	void PrintInfo(Output* pOut);
	bool IsOnFig(int x, int y) const;
	ShapesMenuItem Returnshapestype();//returns type of shape in enum
	void MOVE(Point p1);
};

#endif