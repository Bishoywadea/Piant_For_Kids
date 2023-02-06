#pragma once
#include "Figures/CFigure.h"

class CTriangle : public CFigure
{
private:
    Point p1;
    Point p2;
    Point p3;
    int pvid;
public:
    CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
    CTriangle();
    void Draw(Output* pOut) const;
    void PrintInfo(Output* pOut);
   bool IsOnFig(int x, int y) ;
    void MOVE(Point p);
	 Point getcenter();
    virtual void GetTheCorner(Point A);
    virtual void Resize(Point A) ;
    ShapesMenuItem Returnshapestype();//returns type of shape in enum
    float area(int x1, int y1, int x2, int y2, int x3, int y3) const;
    virtual void Save(ofstream& OutFile);
    virtual void Load(ifstream& InFile);
    int iffigtype();
};

