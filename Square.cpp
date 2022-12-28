#include "Square.h"

Square::Square(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	LowerRight.x = Center.x + 50;
	LowerRight.y = Center.y + 50;
	UpperLeft.x = Center.x - 50;
	UpperLeft.y = Center.y - 50;
}

void Square::Draw(Output* pOut) const
{
	pOut->DrawSq(Center, FigGfxInfo, Selected);
}

void Square::PrintInfo(Output* pOut)
{
	string c = to_string(Center.x) + "," + to_string(Center.y);
	string Id = to_string(ID);
	string isselected = to_string(Selected);

	pOut->PrintMessage("Figure type:Square,Center: " + c + " ID: " + Id + " Is selected: " + isselected);

}

bool Square::IsOnFig(int x, int y) const
{
	Point P;
	P.x = x;
	P.y = y;
	//to see if the point lie on the sqr or not //BISHOY
	if (P.x >= UpperLeft.x && P.x <= LowerRight.x && P.y >= UpperLeft.y && P.y <= LowerRight.y)
		return 1;
	else return 0;
}

Point Square::MOVE(Point p)
{
	Point C0=Center;
	Center.x = p.x;
	Center.y = p.y;

}

void Square::Save(ofstream& OutFile)
{
	OutFile << "SQUARE\t" << pvid << "\t" << Center.x << "\t" << Center.y << "\t" << ConvertColorToString(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
	{
		OutFile << ConvertColorToString(FigGfxInfo.FillClr) << endl;
	}
	else
	{
		OutFile << "BEIGE" << endl;
	}
}

void Square::Load(ifstream& InFile)
{
	//loading the parameters with a specific format
	string DrawClr;
	string FillClr;
	InFile >> pvid >> Center.x >> Center.y;
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
	Selected = false;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	LowerRight.x = Center.x + 50;
	LowerRight.y = Center.y + 50;
	UpperLeft.x = Center.x - 50;
	UpperLeft.y = Center.y - 50;
}
