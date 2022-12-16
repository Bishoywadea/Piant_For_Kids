#include "CHexagon.h"

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
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

bool CHexagon::IsOnFig(int x, int y) const  //Checks to deciding the click is on figure or not //BISHOY
{ 
	Point P;
	P.x = x;
	P.y = y;
	//to see if the point on the hexa or not //BISHOY
	return (50 >= CalcDistance(Center, P));
}
