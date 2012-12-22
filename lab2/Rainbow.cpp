#include "Rainbow.h"
#include <windows.h>
#include <conio.h>
#include <math.h>


Rainbow::Rainbow(int col, int x, int y, int r, int R)
    :Figure(col,x,y),
    r(r), R(R)
{
}

void Rainbow::calcParams(float & perimeter, float & area) const
{
    perimeter=M_PI*(R+r)+2*(R-r);
    area=M_PI*(R*R-r*r)/2;
}

void Rainbow::setSizes(int r, int R)
{
    this->r=r;
    this->R=R;
}

void Rainbow::setPos(int x, int y)
{
    this->x=x;
    this->y=y;
}


void Rainbow::draw() const
{
    if(isVisible())
    {

    HPEN pen = CreatePen (PS_SOLID, 2, decodeColor(getBorderColor()));
    SelectObject (dc, pen);

    MoveToEx(dc, x+r, y, NULL);
    ArcTo(dc, x-R, y-R, x+R, y+R, x+R, y, x-R, y);
    MoveToEx(dc, x+r, y, NULL);
    ArcTo(dc, x-r, y-r, x+r, y+r, x+r, y, x-r, y);
    LineTo(dc, x-R, y);

    }
}

void Rainbow::show(HDC dc)
{
    this->dc=dc;
    draw();
}

