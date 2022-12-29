#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	SHAPES_MENU,
	BACK_ICON,
	COLOUR_MENU,
	BACK,
	DRAW_RECT,		//Draw Rectangle
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	ACT_RED,
	ACT_ORANGE,
	ACT_YELLOW,
	ACT_GREEN,
	HIDE_SHAPES,
	HIDE_SHAPSANDCOLOURS,
	HIDE_COLOURS,
	ACT_DELETE,
	ACT_SELECT,
	ACT_MOVE,
	ACT_UNDO,
	ACT_SAVE,
	ACT_LOAD,
	ACT_CHNGDRAWCOLOUR,
	ACT_REDO,
	ACT_BLUE,
	ACT_BLACK,
	DRAW_CIRCLE,
	DRAW_HEXAGON,
	DRAW_TRIANGLE,
	DRAW_SQUARE,
	ACT_DRAWMOOD,
	ACT_HIDESHAPES,
	ACT_HIDECOLOURS,
	ACT_HIDESHAPESANDCOLOURS,
	ACT_CLEARALL,
	TO_PLAY,
	Sound,
	Drag,
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes  (DONE)
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif