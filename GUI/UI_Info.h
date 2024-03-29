#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface


enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_SHAPES,
	MODE_Fill_COLOUR,
	MODE_Draw_COLOUR,
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SHAPES,
	ITM_COLOUR,		//Recangle item in menu
	ITM_SELECT,
	ITM_DELETE,
	ITM_MOVE,
	ITM_UNDO,
	ITM_REDO,		//TODO: Add more items names here  (DONE)
	ITM_STARTREC,
	ITM_STOPREC,
	ITM_PLAYREC,
	ITM_PLAYMOOD,
	ITM_SAVE,
	ITM_LOAD,
	ITM_CLEARALL,
	ITM_DRAWCOLOUR,
	ITM_SOUND,
	ITM_Drag,
	ITM_Resize,
	ITM_EXIT,//Exit item
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
};

enum ShapesMenuItem //The items of the Draw menu (you should add more items)
{
	ITM_RECT,		//Recangle item in menu
	ITM_CIR,
	ITM_SQU,
	ITM_TRI,
	ITM_HEX,
	ITM_BACk,
	SHAPES_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum ColourMenuItem //The items of the Draw menu (you should add more items)
{
	ITM_RED,		//Recangle item in menu
	ITM_BLUE,
	ITM_BLACK,
	ITM_GREEN,
	ITM_ORANGE,
	ITM_YELLOW,
	ITM_BACK,
	COLOUR_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	ITM_DRAWMOOD,
	ITM_HIDESHAPES,
	ITM_HIDECOLOURS,
	ITM_HIDESHAPESANDCOLOURS,//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here  (DONE)

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool Sound;
	/// Add more members if needed

}UI;	//create a global object UI

#endif