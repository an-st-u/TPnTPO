#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include "base.h"


#define MAX_FIGURES_COUNT 100

class Figure : public Base
{
    unsigned int count;
    Base *objects[MAX_FIGURES_COUNT];

public:
    Figure();
    ~Figure();
    void add(Base *b);
    void show();
    void hide();
    void move(int dx, int dy);


	//void move1(int _x1, int _y1, int _x2, int _y2);
};

#endif
