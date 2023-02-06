#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	if (UI.FillColor != UI.BkGrndColor)
	{
		FigGfxInfo.isFilled = 1;
		FigGfxInfo.FillClr = UI.FillColor;

	}
	else
	{
		FigGfxInfo.isFilled = 0;
	}
	Selected = false;
	ID++;
	FCcount=0;
	DCcount=0;
}

ShapesMenuItem CFigure::Returnshapestype()
{
	return ShapesMenuItem();
}

CFigure::CFigure()
{
	FCcount = 0;
	DCcount = 0;
}

int CFigure::ID = 0;

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr;
    DCarr[DCcount]=Dclr;
	DCcount++;

}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
	UI.FillColor=Fclr;
	FCarr[FCcount]=Fclr;
	FCcount++;
}

double CFigure::CalcDistance(Point A, Point B) const
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
void CFigure::undoFC()
{
	if(FCcount-1==0)
	{
		FigGfxInfo.isFilled=false;
		FCcount--;
	}
	else
	{
		FigGfxInfo.FillClr=FCarr[FCcount-2];
		FCcount--;
}
}
void CFigure::clearcolor()
{
	UI.FillColor=UI.BkGrndColor;         //Clearing color before playing recordings


}
void CFigure::undoDC()
{
	if(FCcount-1==0)
	{
		FigGfxInfo.isFilled=false;
		DCcount--;
	}
	else
	{
		FigGfxInfo.DrawClr=DCarr[DCcount-2];
		DCcount--;


}
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

color CFigure::ConvertStringToColor(string name)
{
	if (name == "RED")
	{
		return RED;
	}

	else if (name == "BLACK")
	{
		return BLACK;
	}

	else if (name == "BLUE")
	{
		return BLUE;
	}

	else if (name == "GREEN")
	{
		return GREEN;
	}

	else if (name == "ORANGE")
	{
		return ORANGE;
	}

	else if (name == "YELLOW")
	{
		return YELLOW;
	}

	else
	{
		return WHITE;
	}
}
bool CFigure::IsFilled()
{
	return FigGfxInfo.isFilled;
}
int CFigure::getfigcolour()
{
	if (FigGfxInfo.isFilled) {
		color r = FigGfxInfo.FillClr;
		if (r == RED)
			return 0;
		else if (r == BLUE)
			return 1;
		else if (r == BLACK)
			return 2;
		else if (r == GREEN)
			return 3;
		else if (r == ORANGE)
			return 4;
		else if (r == YELLOW)
			return 5;
		else
			return -1;
	}
}
color CFigure::getfigcolorascolor()
{
	return color(FigGfxInfo.FillClr);
}

