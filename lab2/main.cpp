#include <iostream>
#include "Rainbow.h"
#include "FRainbow.h"
#include <locale.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
  setlocale(LC_ALL,"Russian");

  int val,filled,i;

  Rainbow *rb = new Rainbow;
  FRainbow *frb = new FRainbow;

  cout<<"����� ����� ������� (0 - ������, 1 - �������, 2 - �������, 3 - �����, 4 - �����):\n";
  cin>>val;
  rb->setBorderColor(val); frb->setBorderColor(val);

  cout<<"����� ����� ���������� (0 - ������, 1 - �������, 2 - �������, 3 - �����, 4 - �����):\n";
  cin>>val;
  frb->setFillColor(val);

  system("cls");

  rb->setPos(100,100);  frb->setPos(100,220);
  rb->setSizes(50,100); frb->setSizes(50,100);

  //���������
  HWND console = FindWindow("ConsoleWindowClass",NULL);
  HDC dc = GetDC(console);
  HPEN wpen=CreatePen (PS_SOLID, 1, RGB(255, 255, 255));
  SelectObject (dc, wpen);

  rb->show(dc); frb->show(dc);
  rb->Move(200,0);     frb->Move(200,0);
  rb->setSizes(30,70); frb->setSizes(30,70);
  rb->show(dc); frb->show(dc);

  ReleaseDC(console, dc);

  cin>>val;
}

