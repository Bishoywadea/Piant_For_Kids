#pragma once
#include "Figures/CFigure.h"
class CHexagon :public CFigure
{
private:
    Point Center;
public:
   CHexagon(Point, GfxInfo FigureGfxInfo);
   virtual void Draw(Output* pOut) const;
   void PrintInfo(Output* pOut);
   virtual bool IsOnFig(int x, int y) ;  //Checks to deciding the click is on figure or not //BISHOY
};

