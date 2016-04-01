#pragma once
#include "Okr.h"
#ifndef ARC_H
#define ARC_H
class Arc: public Okr
{
public:
    int x, y, sa, ea, r;

    Arc() :Okr() {};
    Arc(int _x, int _y, int _sa, int _ea, int _r) : x(_x),y(_y),sa(_sa),ea(_ea),r(_r) {}
    virtual void Hide();
    virtual void Show();
    virtual void Move(int dx, int dy);
   virtual void output(char* fnameo);
};

#endif
