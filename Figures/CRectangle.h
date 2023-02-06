#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"
#include<fstream>
class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point UpperRight;
	Point LowerLeft;
	Point SelectedCorner;
	int pvid;
	
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Draw(Output* pOut) const;
	void PrintInfo(Output* pOut);
	bool IsOnFig(int x, int y) ;
	 Point getcenter();
	ShapesMenuItem Returnshapestype();//returns type of shape in enum
	void MOVE(Point p1);
	void SetCorners(Point A);
	virtual void GetTheCorner(Point A);
	virtual void Resize(Point A) ;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
	int iffigtype();
};

#endif