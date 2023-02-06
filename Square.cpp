#include "Square.h"

Square::Square(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	side = 100;
	UpdateCorner();
	pvid = ID;
}

Square::Square()
{
}

void Square::Draw(Output* pOut) const
{
	pOut->DrawSq(Center, FigGfxInfo, Selected,side);
}

void Square::PrintInfo(Output* pOut)
{
	string c = to_string(Center.x) + "," + to_string(Center.y);
	string Id = to_string(ID);
	string isselected = to_string(Selected);

	pOut->PrintMessage("Figure type:Square,Center: " + c + " ID: " + Id + " Is selected: " + isselected);

}

bool Square::IsOnFig(int x, int y) 
{
	Point P;
	P.x = x;
	P.y = y;
	//to see if the point lie on the sqr or not //BISHOY
	if (P.x >= UpperLeft.x && P.x <= LowerRight.x && P.y >= UpperLeft.y && P.y <= LowerRight.y)
		return 1;
	else return 0;
}

ShapesMenuItem Square::Returnshapestype()
{
	return ShapesMenuItem(ITM_SQU);
}

void Square::MOVE(Point p)
{
	C0=Center;
	Center.x = p.x;
	Center.y = p.y;
	LowerRight.x = Center.x + 50;
	LowerRight.y = Center.y + 50;
	UpperLeft.x = Center.x - 50;
	UpperLeft.y = Center.y - 50;

}
void Square::UpdateCorner()
{
	LowerRight.x = Center.x + side / 2;
	LowerRight.y = Center.y + side / 2;
	UpperLeft.x = Center.x - side / 2;
	UpperLeft.y = Center.y - side / 2;
}
Point Square::getcenter()
{
	return C0;

}

void Square::GetTheCorner(Point A)
{
	Point UpperRight;
	UpperRight.x = UpperLeft.x + side;
	UpperRight.y = UpperLeft.y;
	Point LowerLeft;
	LowerLeft.x = LowerRight.x - side;
	LowerLeft.y = LowerRight.y;
	float dist1 = CalcDistance(A, UpperLeft);
	float dist2 = CalcDistance(A, UpperRight);
	float dist3 = CalcDistance(A, LowerLeft);
	float dist4 = CalcDistance(A, LowerRight);
	float closer = min(min(dist1, dist2), min(dist3, dist4));
	if (closer == dist1)
	{
		SelectedCorner = UpperLeft;
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
		SelectedCorner = LowerRight;
	}
}

void Square::Resize(Point A)
{
	side = CalcDistance(Center, A) * 1.414;
	LowerRight.x = Center.x + side / 2;
	LowerRight.y = Center.y + side / 2;
	UpperLeft.x = Center.x - side / 2;
	UpperLeft.y = Center.y - side / 2;
}

void Square::Save(ofstream& OutFile)
{
	OutFile << "SQUARE\t" << pvid << "\t" << Center.x << "\t" << Center.y << "\t" <<side<< "\t" << ConvertColorToString(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
	{
		OutFile << ConvertColorToString(FigGfxInfo.FillClr) << endl;
	}
	else
	{
		OutFile << "NOCOLOR" << endl;
	}
}

void Square::Load(ifstream& InFile)
{
	//loading the parameters with a specific format
	string DrawClr;
	string FillClr;
	InFile >> pvid >> Center.x >> Center.y>>side;
	InFile >> DrawClr;
	FigGfxInfo.DrawClr = ConvertStringToColor(DrawClr);
	InFile >> FillClr;
	if (FillClr == "NOCOLOR")
	{
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = ConvertStringToColor(FillClr);
	}
	Selected = false;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	UpdateCorner();
}

int Square::iffigtype()
{
	return 2;
}
