#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
#include <windows.h>

class Figure
{
private:
  int c; // ����
  bool visible;
protected:
  int x,y; // ������� �����
  virtual void draw() const = 0;
public:
  Figure(int c = 0, int x = 0, int y = 0);
  virtual ~Figure(){};
  void Move(int dx, int dy); // �������� ������ �� (dx,dy) � ������ �������
  virtual void setBorderColor(int c); // ���������� ���� ������ � ������ �������
  int getBorderColor() const; // �������� ����
  COLORREF decodeColor(int col) const;
  void setVisible( bool isVisible );    // ��������/�������� ������
  bool isVisible() const; // ������� ���������
  virtual void calcParams(float & perimeter, float & area) const = 0;// ��������� �������� � ������� ������
 };

#endif // FIGURE_H_INCLUDED
