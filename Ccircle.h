#pragma once
#include "Figures/CFigure.h"
class Ccircle :public CFigure
{
private:
	Point Center;
	Point Radius;
public:
	Ccircle(Point, Point, GfxInfo FigureGfxInfo);
	 void Draw(Output* pOut) const;
	 void PrintInfo(Output* pOut);


};

