#include "CFigure.h"
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	Ccount=0;
}

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
	Carr[Ccount]=Fclr;
	Ccount++;

}
void CFigure::undof()
{
	if(Ccount-1==0)
	{
		FigGfxInfo.isFilled=false;
		Ccount--;
	}
	else
	{
		FigGfxInfo.FillClr=Carr[Ccount-2];
		Ccount--;
}
}
double CFigure::CalcDistance(Point A, Point B) const
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

