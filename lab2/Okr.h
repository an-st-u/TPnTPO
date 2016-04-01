#pragma once
#include "Point.h"
#ifndef OKR_H
#define OKR_H

class Okr: public Point
{
public:
    int x, y, r;

    Okr() :Point() {};
    Okr(int _x, int _y, int _r) : x(_x),y(_y),r(_r) {}
    virtual void Hide();
    virtual void Show();
    virtual void Move(int dx, int dy);
    virtual void output(char* fnameo);
};
#endif

