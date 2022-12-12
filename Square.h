#pragma once
#include "Figures/CFigure.h"
class Square :
    public CFigure
{
private:

		Point Center;
		
	public:
		Square(Point, GfxInfo FigureGfxInfo);
		virtual void Draw(Output* pOut) const;
		void PrintInfo(Output* pOut);
	};



