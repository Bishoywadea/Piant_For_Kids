#include "CHexagon.h"
#include<fstream>
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	RightUp.x = Center.x + 50;
	RightUp.y = Center.y - ((0.866) * 100);
	RightDown.x = Center.x + 50;
	RightDown.y = Center.y + ((0.866) * 100);
	Right.x = Center.x + 100;
	Right.y = Center.y;
	LeftUp.x = Center.x - 50;
	LeftUp.y = Center.y - ((0.866) * 100);
	LeftDown.x = Center.x - 50;
	LeftDown.y = Center.y + ((0.866) * 100);
	Left.x = Center.x - 100;
	Left.y = Center.y;
	pvid = ID;
}

CHexagon::CHexagon()
{
}

void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHexa(Center, FigGfxInfo, Selected);
}

void CHexagon::PrintInfo(Output* pOut)
{
	string c = to_string(Center.x)+","+to_string(Center.y);
	string Id = to_string(ID);
	string isselected = to_string(Selected);
	pOut->PrintMessage("Figure type: Hexagon,Center: "+c+" ID: "+Id+" Is selected: "+isselected);
	
}

void CHexagon::MOVE(Point p)
{
	Center.x = p.x;
	Center.y = p.y;
	RightUp.x = Center.x + 50;
	RightUp.y = Center.y - ((0.866) * 100);
	RightDown.x = Center.x + 50;
	RightDown.y = Center.y + ((0.866) * 100);
	Right.x = Center.x + 100;
	Right.y = Center.y;
	LeftUp.x = Center.x - 50;
	LeftUp.y = Center.y - ((0.866) * 100);
	LeftDown.x = Center.x - 50;
	LeftDown.y = Center.y + ((0.866) * 100);
	Left.x = Center.x - 100;
	Left.y = Center.y;
}

float CHexagon::area(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
}

bool CHexagon::IsOnFig(int x, int y) const  //Checks to deciding the click is on figure or not //BISHOY
{ 
	if (x >= LeftUp.x && x <= RightUp.x && y >= LeftUp.y && y <= LeftDown.y)
	{
		return true;
	}
	float A = area(RightDown.x, RightDown.y, RightUp.x, RightUp.y, Right.x, Right.y);
	float A1 = area(x, y, RightUp.x, RightUp.y, Right.x, Right.y);
	float A2 = area(RightDown.x, RightDown.y, x, y, Right.x, Right.y);
	float A3 = area(RightDown.x, RightDown.y, RightUp.x, RightUp.y, x, y);
	if (A == A1 + A2 + A3)
	{
		return true;
	}
	A1 = area(x, y, LeftUp.x, LeftUp.y, Left.x, Left.y);
	A2 = area(LeftDown.x, LeftDown.y, x, y, Left.x, Left.y);
	A3 = area(LeftDown.x, LeftDown.y, LeftUp.x, LeftUp.y, x, y);
	if (A == A1 + A2 + A3)
	{
		return true;
	}
	return false;
}
ShapesMenuItem CHexagon::Returnshapestype()
{
	return ITM_HEX;
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "HEXAGON\t" << pvid << "\t" << Center.x << "\t" << Center.y << "\t" << ConvertColorToString(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
	{
		OutFile << ConvertColorToString(FigGfxInfo.FillClr) << endl;
	}
	else
	{
		OutFile << "NOCOLOR" << endl;
	}
}

void CHexagon::Load(ifstream& InFile)
{
	string DrawClr;
	string FillClr;
	InFile >> pvid >> Center.x >> Center.y;
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
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Selected = false;
}
ShapesMenuItem CHexagon::Returnshapestype()
{
	return ITM_HEX;
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "HEXAGON\t" << pvid << "\t" << Center.x << "\t" << Center.y << "\t" << ConvertColorToString(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
	{
		OutFile << ConvertColorToString(FigGfxInfo.FillClr) << endl;
	}
	else
	{
		OutFile << "BEIGE" << endl;
	}
}

void CHexagon::Load(ifstream& InFile)
{
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
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Selected = false;
}
