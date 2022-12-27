#pragma once
#include "Figures/CFigure.h"
class CHexagon :public CFigure
{
private:
    Point Center;
    Point RightUp;
    Point RightDown;
    Point Right;
    Point LeftUp;
    Point LeftDown;
    Point Left;
    int pvid;
public:
   CHexagon(Point, GfxInfo FigureGfxInfo);
   CHexagon();
   virtual void Draw(Output* pOut) const;
   void PrintInfo(Output* pOut);
   void MOVE(Point p);
   float area(int x1, int y1, int x2, int y2, int x3, int y3) const; //function to be used in IsOnFig function
   virtual bool IsOnFig(int x, int y) const;  //Checks to deciding the click is on figure or not //BISHOY
   ShapesMenuItem Returnshapestype();
   virtual void Save(ofstream& OutFile);
   virtual void Load(ifstream& InFile);
};

