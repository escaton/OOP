#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <iostream>

class Fraction
{
private:
    int integer;
    int fract;
public:
    Fraction(const int integer = 0, const int fract = 0) :
        integer(integer),
        fract(fract)
    {
        this->integer = integer;
        this->fract = fract;
    };

    Fraction(const Fraction& clone)
    {
        this->integer = clone.getInt();
        this->fract = clone.getFract();
    };

    Fraction& operator=(const Fraction& clone)
    {
        this->integer = clone.getInt();
        this->fract = clone.getFract();
    };

    Fraction& operator=(const int integer)
    {
        this->integer = integer;
        this->fract = 0;
    };

    Fraction& operator+(const Fraction& elem);
    Fraction& operator+(const int elem);
    Fraction& operator-(const Fraction& elem);
    Fraction& operator-(const int elem);
    bool operator==(const Fraction& elem);
    bool operator==(const int elem);
    bool operator!=(const Fraction& elem);
    bool operator!=(const int elem);

    int getInt() const;
    int getFract() const;
    void print();
};

#endif // FRACTION_H_INCLUDED

