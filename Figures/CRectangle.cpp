#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::PrintInfo(Output* pOut)
{
	string c = to_string(Corner1.x) + "," + to_string(Corner1.y)+" "+ to_string(Corner2.x) + "," + to_string(Corner2.y);
	string Id = to_string(ID);
	string isselected = to_string(Selected);

	pOut->PrintMessage("Figure type:Rectangle,Center: " + c + " ID: " + Id + " Is selected: " + isselected);

}

bool CRectangle::IsOnFig(int x, int y) const
{
	Point P;
	P.x = x;
	P.y = y;
	//to see if the point lie on the rec or not //BISHOY
	if (P.x >= min(Corner1.x, Corner2.x) && P.x <= max(Corner2.x, Corner1.x) && P.y >= min(Corner1.y, Corner2.y) && P.y <= max(Corner2.y, Corner1.y))
		return 1;
	else return 0;
}

