#include "CHexagon.h"
#include<fstream>
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	pvid=ID;
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
	
}


bool CHexagon::IsOnFig(int x, int y) const  //Checks to deciding the click is on figure or not //BISHOY
{ 
	Point P;
	P.x = x;
	P.y = y;
	//to see if the point on the hexa or not //BISHOY
	return (50 >= CalcDistance(Center, P));
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "HEXAGON\t" << pvid << "\t" << Center.x << "\t" << Center.y << "\t" << ConvertColorToString(UI.DrawColor) << "\t";
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
