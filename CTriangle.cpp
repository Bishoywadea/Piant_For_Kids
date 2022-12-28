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

bool CTriangle::IsOnFig(int x, int y) const
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
Point CTriangle::MOVE(Point p)
{
	Point Center;
	Center.x = ((p1.x + p2.x + p3.x) / 3);
	Center.y= ((p1.y + p2.y + p3.y) / 3);
	float deltaxone = Center.x-p1.x;
	float deltayone = Center.y - p1.y;
	float deltaxtwo = Center.x - p2.x;
	float deltaytwo = Center.y - p2.y;
	float deltaxthree = Center.x - p3.x;
	float deltaythree = Center.y - p3.y;
	p1.x = p.x - deltaxone;
	p1.y = p.y - deltayone;
	p2.x = p.x - deltaxtwo;
	p2.y = p.y - deltaytwo;
	p3.x = p.x - deltaxthree;
	p3.y = p.y - deltaythree;
	return Center;

}

ShapesMenuItem CTriangle::Returnshapestype()
{
	return ITM_TRI;
}




float CTriangle::area(int x1, int y1, int x2, int y2, int x3, int y3) const


float CTriangle::area(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "TRIANGLE\t" << pvid << "\t" << p1.x << "\t" << p1.y << "\t" << p2.x << "\t" << p2.y << "\t" << p3.x << "\t" << p3.y << "\t" << ConvertColorToString(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
	{
		OutFile << ConvertColorToString(FigGfxInfo.FillClr) << endl;
	}
	else
	{
		OutFile << "BEIGE" << endl;
	}
}

void CTriangle::Load(ifstream& InFile)
{
	string DrawClr;
	string FillClr;
	InFile >> pvid >> p1.x >> p1.y >> p2.x >> p2.y>>p3.x>>p3.y;
	InFile >> DrawClr;
	FigGfxInfo.DrawClr = ConvertStringToColor(DrawClr);
	InFile >> FillClr;
	if (FillClr == "BEIGE")
	{
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = ConvertStringToColor(FillClr);
	}
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Selected = false;
}

