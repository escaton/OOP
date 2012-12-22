#ifndef FRAINBOW_H_INCLUDED
#define FRAINBOW_H_INCLUDED
#include "Rainbow.h"

class FRainbow:public Rainbow
{
public:
    HDC dc;
    FRainbow(int fill_col=2);
    virtual ~FRainbow(){};
    void draw();
    void show(HDC dc);
    void setFillColor(int col);
private:
    int fc;
};


#endif // FRAINBOW_H_INCLUDED
