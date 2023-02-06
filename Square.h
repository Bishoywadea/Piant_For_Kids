#pragma once
#include "Figures/CFigure.h"
class Square :
    public CFigure
{
private:

	Point Center;
	Point UpperLeft;
	Point LowerRight;
	Point LowerLeft;
	Point UpperRight;
	float side;
	Point SelectedCorner;
	int pvid;
public:
	Square(Point, GfxInfo FigureGfxInfo);
	Square();
	virtual void Draw(Output* pOut) const;
	void PrintInfo(Output* pOut);
	 Point getcenter();
	virtual bool IsOnFig(int x, int y) ;
	ShapesMenuItem Returnshapestype();//returns type of shape in enum
	void MOVE(Point );
	void UpdateCorner();
	virtual void GetTheCorner(Point A);
	virtual void Resize(Point A);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
	int iffigtype();
};



