#pragma once
#include "Figures/CFigure.h"

class CTriangle :
    public CFigure
{
private:
    Point p1;
    Point  p2;
    Point p3;
public:
    CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
     void Draw(Output* pOut) const;
    void PrintInfo(Output* pOut);
};

