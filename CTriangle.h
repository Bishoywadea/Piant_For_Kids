#pragma once
#include "Figures/CFigure.h"

class CTriangle : public CFigure
{
private:
    Point p1;
    Point p2;
    Point p3;
    /*int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;*/
public:
    CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
    void Draw(Output* pOut) const;
    void PrintInfo(Output* pOut);
    bool IsOnFig(int x, int y) const;
    Point MOVE(Point p);
    float area(int x1, int y1, int x2, int y2, int x3, int y3) const;
};

