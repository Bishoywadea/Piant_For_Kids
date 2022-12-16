#pragma once
#include "Figures/CFigure.h"
class Square :
    public CFigure
{
private:

	Point Center;
	Point UpperLeft;
	Point LowerRight;
public:
	Square(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void PrintInfo(Output* pOut);
	virtual bool IsOnFig(int x, int y) const;
};



