#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID++;
}

int CFigure::ID = 0;

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

double CFigure::CalcDistance(Point A, Point B) const
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

string CFigure::ConvertColorToString(color c)
{
	if (c == RED)
	{
		return "RED";
	}
	else if (c == BLACK)
	{
		return "BLACK";
	}
	else if (c == BLUE)
	{
		return "BLUE";
	}
	else if (c == GREEN)
	{
		return "GREEN";
	}
	else if (c == ORANGE)
	{
		return "ORANGE";
	}
	else if (c == YELLOW)
	{
		return "YELLOW";
	}
	else
	{
		return "NO COLOR";
	}
}


