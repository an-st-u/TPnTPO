#pragma once
#include "Base.h"
#ifndef POINT_H
#define POINT_H
class Point: public Base
{
public:
    int x, y, col;

    Point() :Base() {};
    Point(int _x, int _y, int  _col) : x(_x), y(_y), col(_col) {}
    Point(int x, int y);
    virtual void Hide();
    virtual void Show();
    virtual void Move(int dx, int dy);
    virtual void output(char* fnameo);
};

#endif POINT_H
