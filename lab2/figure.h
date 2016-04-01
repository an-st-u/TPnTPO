#pragma once
#include "Base.h"
#include "line.h"
#include "okr.h"
#include "point.h"
#include "arc.h"
#include <stdio.h>
#include <graphics.h>
class Figure :public Base
{

public:
    int N;
    Base *A[100];
    Figure();
    void Hide();
    void Show();
    void Move(int dx, int dy);
    void Add(Base *Ptr);
    void read(char* fname);
    void write(char* fnameo);
};


