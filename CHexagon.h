#pragma once
#include "Figures/CFigure.h"
class CHexagon :public CFigure
{
private:
    Point Center;
    int pvid;
public:
   CHexagon(Point, GfxInfo FigureGfxInfo);
   CHexagon();
   virtual void Draw(Output* pOut) const;
   void PrintInfo(Output* pOut);
   void MOVE(Point p);
   virtual bool IsOnFig(int x, int y) const;  //Checks to deciding the click is on figure or not //BISHOY
   ShapesMenuItem Returnshapestype();
   virtual void Save(ofstream& OutFile);
   virtual void Load(ifstream& InFile);
};

