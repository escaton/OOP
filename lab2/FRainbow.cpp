#include "FRainbow.h"
#include <iostream>
#include <conio.h>
using std::cout;

FRainbow::FRainbow(int Fcol):fc(Fcol)
{
}

void FRainbow::draw()
{
    if(isVisible()){

    COLORREF Bcol=decodeColor(getBorderColor());
    if (fc==4) Bcol=decodeColor(4); //Чтобы сработал случай с чёрной границей на чёрном фоне

    HBRUSH brush=CreateSolidBrush(decodeColor(fc));
    SelectObject (dc, brush);

    HPEN pen = CreatePen(PS_SOLID, 1,Bcol);
    SelectObject (dc, pen);

    MoveToEx(dc, x+r, y, NULL);
    ArcTo(dc, x-R, y-R, x+R, y+R, x+R, y, x-R, y);
    MoveToEx(dc, x+r, y, NULL);
    ArcTo(dc, x-r, y-r, x+r, y+r, x+r, y, x-r, y);
    LineTo(dc, x-R-1, y-1);
    FloodFill(dc,x,y-(R+r)/2,Bcol);

    DeleteObject(pen);
    DeleteObject(brush);
    }
}

void FRainbow::show(HDC dc)
{
    this->dc=dc;
    draw();
}

void FRainbow::setFillColor(int Col)
{
  fc=Col;
}




