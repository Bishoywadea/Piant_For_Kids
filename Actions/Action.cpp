#include "Action.h"

const string Action::turnenumshapesintostring(int i)
{
    switch (i)
    {
    case 0:
        return string("RECTANGLE");
    case 1:
        return string("CIRCLE");
    case 2:
        return string("SQUARE");
    case 3:
        return string("TRIANGLE");
    case 4:
        return string("HEXAGON");

    }
}

const string Action::turnenumcolorsintostring(int i)
{
    switch (i)
    {
    case 0:
        return string("RED");
    case 1:
        return string("BLUE");
    case 2:
        return string("BLACK");
    case 3:
        return string("GREEN");
    case 4:
        return string("ORANGE");
    case 5:
        return string("YELLOW");
    }
}