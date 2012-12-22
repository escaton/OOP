#include "Figure.h"
#include <windows.h>

void Figure::setBorderColor(int Col)
{
    if (visible == true)
      c=Col;
}

void Figure::Move(int dx,int dy)
{
    if(visible==true)
    {
        x+=dx;
        y+=dy;
    }
}

int Figure::getBorderColor() const
{
    return c;
}

void Figure::setVisible(bool Vis)
{
  visible=Vis;
}

bool Figure::isVisible() const
{
  return visible;
}

COLORREF Figure::decodeColor(int col) const
{
    switch(col+1)
    {
        case 1:
            return RGB(0,0,0);//black
        case 2:
            return RGB(255,0,0);//red
        case 3:
            return RGB(0,255,0);//green
        case 4:
            return RGB(0,0,255);//blue
        case 5:
            return RGB(255,255,255);//white
    }
}

Figure::Figure(int Col, int X, int Y):
        c(Col),
        visible(1),
        x(X),
        y(Y)
{}
