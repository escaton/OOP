#include <iostream>
#include "fraction.h"

Fraction& Fraction::operator+(const Fraction& elem)
{
    this->integer+=elem.getInt()/10;
    this->fract+=elem.getFract()%10;
    return *this;
}

Fraction& Fraction::operator+(const int elem)
{
    this->integer+=elem;
    return *this;
}

Fraction& Fraction::operator-(const Fraction& elem)
{
    this->fract-=elem.getFract();
    if (this->fract<0)
    {
        this->integer-=1;
        this->fract+=10;
    }
    this->integer-=elem.getInt();
    return *this;
}

Fraction& Fraction::operator-(const int elem)
{
    this->integer-=elem;
    return *this;
}

bool Fraction::operator==(const Fraction& elem)
{
    return (this->integer==elem.getInt() && this->fract==elem.getFract());
}

bool Fraction::operator==(const int elem)
{
    return (this->integer==elem && this->fract==0);
}

bool Fraction::operator!=(const Fraction& elem)
{
    return !(this->integer==elem.getInt() && this->fract==elem.getFract());
}

bool Fraction::operator!=(const int elem)
{
    return !(this->integer==elem && this->fract==0);
}
int Fraction::getInt() const
{
    return this->integer;
}

int Fraction::getFract() const
{
    return this->fract;
}

void Fraction::print()
{
    std::cout<<std::endl;
    std::cout<<this->integer<<'.'<<this->fract<<std::endl;
}

