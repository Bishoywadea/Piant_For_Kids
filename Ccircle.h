#pragma once
#include "Figures/CFigure.h"
class Ccircle :public CFigure
{
private:
	Point Center;
	Point Radius;
    int radius; //added to be used in IsOnFig function //BISHOY
public:
	 Ccircle(Point, Point, GfxInfo FigureGfxInfo);
	 void Draw(Output* pOut) const;
	 void PrintInfo(Output* pOut);
	 virtual bool IsOnFig(int x, int y) ;//Checks to deciding the click is on figure or not //BISHOY

};

