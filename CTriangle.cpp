#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	p1 = P1;
	p2 = P2;
	p3 = P3;
	/*x1 = p1.x;
	y1 = p1.y;
	x2 = p2.x;
	y2 = p2.y;
	x3 = p3.x;
	y3 = p3.y;*/
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

bool CTriangle::IsOnFig(int x, int y)
{
	float A = area(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
	float A1 = area(x, y, p2.x, p2.y, p3.x, p3.y);
	float A2 = area(p1.x, p1.y, x, y, p3.x, p3.y);
	float A3 = area(p1.x, p1.y, p2.x, p2.y, x, y);
	if (A == A1 + A2 + A3)
	{
		return true;
	}
	return false;
}

float CTriangle::area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
}

