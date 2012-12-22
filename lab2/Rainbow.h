#ifndef RAINBOW_H_INCLUDED
#define RAINBOW_H_INCLUDED
#include "Figure.h"
#include <windows.h>

class Rainbow:public Figure
{
public:
    HDC dc;
    Rainbow(int col = 0, int x = 0, int y = 0, int r = 0, int R = 0);
    void move(int dx, int dy);
    void setPos(int x, int y);
    void setSizes(int r, int R);
    void calcParams(float &perimeter, float &area) const;
    void calcPoints();
    void show(HDC dc);

protected:
    int r; int R;
    void draw() const;
};

#endif // RAINBOW_H_INCLUDED
