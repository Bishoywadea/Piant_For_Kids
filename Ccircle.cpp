#include "Ccircle.h"
#include<fstream>
Ccircle::Ccircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center= P1;
	Radius= P2;
	radius = CalcDistance(P1, P2);
	pvid = ID;
}

Ccircle::Ccircle()
{
}

void Ccircle::Draw(Output* pOut) const
{
	pOut->DrawCircle(Center, Radius, FigGfxInfo, Selected);
}

void Ccircle::PrintInfo(Output* pOut)
{
	string c = to_string(Center.x) + "," + to_string(Center.y)+" Radius "+to_string(Radius.x)+","+to_string(Radius.y);
	string Id = to_string(ID);
	string isselected = to_string(Selected);

	pOut->PrintMessage("Figure type: Circle,Center: " + c + " ID: " + Id + " Is selected: " + isselected);

}

bool Ccircle::IsOnFig(int x, int y)  //Checks to deciding the click is on figure or not //BISHOY
{
	Point P;
	P.x = x;
	P.y = y;
	//to see if the point lie on the circle or not //BISHOY
	return (radius >= CalcDistance(Center, P));
}

void Ccircle::MOVE(Point p)
{
	C0 = Center;
	float rlen = sqrt(pow((Radius.x - Center.x), 2) + pow((Radius.y - Center.y), 2));
	Center.x = p.x;
	Center.y = p.y;
	Radius.x = p.x + rlen;
	Radius.y = p.y;
	pvid = ID;
}
Point Ccircle::getcenter()
{
	return C0;

}
void Ccircle::GetTheCorner(Point A)
{
}

void Ccircle::Resize(Point A)
{
	Radius = A;
	radius = CalcDistance(A, Center);
}

void Ccircle::Save(ofstream& OutFile)
{
	OutFile << "Circle\t"<< pvid<<"\t" << Center.x << "\t" << Center.y << "\t" << Radius.x << "\t" << Radius.y << "\t" << ConvertColorToString(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
	{
		OutFile << ConvertColorToString(FigGfxInfo.FillClr) << endl;
	}
	else
	{
		OutFile << "NOCOLOR" << endl;
	}
}

void Ccircle::Load(ifstream& InFile)
{
	string DrawClr;
	string FillClr;
	InFile >> pvid >> Center.x >> Center.y >> Radius.x >> Radius.y;
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
	radius = CalcDistance(Center, Radius);
}
int Ccircle::iffigtype()
{
	return 1;
}
ShapesMenuItem Ccircle::Returnshapestype()
{
	return ITM_CIR;
}

