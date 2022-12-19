#include "CRectangle.h"
#include<algorithm>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	pvid = ID;
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
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void CRectangle::MOVE(Point p1)
{
	Point Center;
	Center.x = float(Corner2.x - Corner1.x) / 2.0;
	Center.y = float(Corner2.y - Corner1.y) / 2.0;
	float deltax = float(Corner2.x - Corner1.x) / 2.0;
	float deltay = float(Corner2.y - Corner1.y) / 2.0;
	Corner1.x = p1.x + deltax;
	Corner1.y = p1.y + deltay;
	Corner2.x = p1.x - deltax;
	Corner2.y = p1.y - deltay;
	//Draw(Output* pOut);

}

void CRectangle::Save(ofstream& OutFile)
{
	OutFile << "RECTANGLE\t" << pvid << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << ConvertColorToString(UI.DrawColor) << "\t";
	if (FigGfxInfo.isFilled)
	{
		OutFile << ConvertColorToString(UI.FillColor) << endl;
	}
	else
	{
		OutFile << "NO COLOR" << endl;
	}
}

