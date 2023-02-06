#include "CRectangle.h"
#include<algorithm>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	SelectedCorner = P2;
	pvid = ID;

}

CRectangle::CRectangle()
{
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

bool CRectangle::IsOnFig(int x, int y) 
{
	Point P;
	Point UpperRight;
	UpperRight.x = Corner2.x;
	UpperRight.y = Corner2.y;
	Point LowerLeft;
	LowerLeft.x = Corner1.x;
	LowerLeft.y = Corner1.y;
	P.x = x;
	P.y = y;
	//to see if the point lie on the rec or not //BISHOY
	if (P.x >= min(min(Corner1.x, Corner2.x), min(LowerLeft.x, UpperRight.x)) && P.x <= max(max(Corner2.x, Corner1.x),max(UpperRight.x, LowerLeft.x)) && P.y >= min(min(Corner1.y, Corner2.y), min(LowerLeft.y, UpperRight.y)) && P.y <= max(max(Corner2.y, Corner1.y), max(UpperRight.y, LowerLeft.y)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

ShapesMenuItem CRectangle::Returnshapestype()
{
	return ITM_RECT;
}

void CRectangle::MOVE(Point p1)
{
	C0.x = float(Corner2.x + Corner1.x) / 2.0;
	C0.y = float(Corner2.y + Corner1.y) / 2.0;
	float deltax = float(Corner2.x - Corner1.x) / 2.0;
	float deltay = float(Corner2.y - Corner1.y) / 2.0;
	Corner1.x = p1.x + deltax;
	Corner1.y = p1.y + deltay;
	Corner2.x = p1.x - deltax;
	Corner2.y = p1.y - deltay;
}
Point CRectangle::getcenter()
{
	
   return C0;

}

void CRectangle::SetCorners(Point A)
{
	UpperRight.x = Corner2.x;
	UpperRight.y = Corner2.y;
	LowerLeft.x = Corner1.x;
	LowerLeft.y = Corner1.y;
}

void CRectangle::GetTheCorner(Point A)
{
	SetCorners(A);
	float dist1 = CalcDistance(A, Corner1);
	float dist2 = CalcDistance(A, UpperRight);
	float dist3 = CalcDistance(A, LowerLeft);
	float dist4 = CalcDistance(A, Corner2);
	float closer = min(min(dist1, dist2), min(dist3, dist4));
	if (closer == dist1)
	{
		SelectedCorner = Corner1;
	}
	else if (closer == dist2)
	{
		SelectedCorner = UpperRight;
	}
	else if (closer == dist3)
	{
		SelectedCorner = LowerLeft;
	}
	else
	{
		SelectedCorner = Corner2;
	}
}

void CRectangle::Resize(Point A)
{
	if (SelectedCorner.x == Corner1.x && SelectedCorner.y == Corner1.y)
	{
		SelectedCorner = A;
		Corner1 = A;
	}
	else if (SelectedCorner.x == Corner2.x && SelectedCorner.y == Corner2.y)
	{
		SelectedCorner = A;
		Corner2 = A;
	}
	else if (SelectedCorner.x == UpperRight.x && SelectedCorner.y == UpperRight.y)
	{
		SelectedCorner = A;
		UpperRight = A;
	}
	else
	{
		SelectedCorner = A;
		LowerLeft = A;
	}
}

void CRectangle::Save(ofstream& OutFile)
{
	OutFile << "RECTANGLE\t" << pvid << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << ConvertColorToString(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
	{
		OutFile << ConvertColorToString(FigGfxInfo.FillClr) << endl;
	}
	else
	{
		OutFile << "NOCOLOR" << endl;
	}
}

void CRectangle::Load(ifstream& InFile)
{
	string DrawClr;
	string FillClr;
	InFile >> pvid >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	InFile >> DrawClr;
	FigGfxInfo.DrawClr = ConvertStringToColor(DrawClr);
	InFile >> FillClr;
	if (FillClr == "NOCOLOR")
	{
		FigGfxInfo.isFilled = false;
	}
	else 
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = ConvertStringToColor(FillClr);
	}
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Selected = false;
}

int CRectangle::iffigtype()
{
	return 0;
}

