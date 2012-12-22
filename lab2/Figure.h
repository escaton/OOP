#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
#include <windows.h>

class Figure
{
private:
  int c; // цвет
  bool visible;
protected:
  int x,y; // базовая точка
  virtual void draw() const = 0;
public:
  Figure(int c = 0, int x = 0, int y = 0);
  virtual ~Figure(){};
  void Move(int dx, int dy); // сместить фигуру на (dx,dy) – только видимую
  virtual void setBorderColor(int c); // установить цвет фигуры – только видимой
  int getBorderColor() const; // получить цвет
  COLORREF decodeColor(int col) const;
  void setVisible( bool isVisible );    // показать/спрятать фигуру
  bool isVisible() const; // признак видимости
  virtual void calcParams(float & perimeter, float & area) const = 0;// вычислить периметр и площадь фигуры
 };

#endif // FIGURE_H_INCLUDED
