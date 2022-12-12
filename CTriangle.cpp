#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	p1 = P1;
	p2 = P2;
	p3 = P3;
}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTri(p1, p2, p3, FigGfxInfo, Selected);
}

void CTriangle::PrintInfo(Output* pOut)
{
	string c = to_string(p1.x) + "," + to_string(p1.y) + " " + to_string(p2.x) + "," + to_string(p2.y) + " " + to_string(p3.x) + "," + to_string(p3.y);
	string Id = to_string(ID);
	string isselected = to_string(Selected);

	pOut->PrintMessage("Figure type:Triangle,Coordinates: " + c + " ID: " + Id + " Is selected: " + isselected);

}
