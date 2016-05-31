#pragma once
#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include "Base.h"
#define MAX_FIGURES_COUNT 100

class Figure: public Base
{
	unsigned int count;
	Base **objects;

public:
	Figure();
	Figure(int quan);
	~Figure();
	void add(Base *b);
	void show();
	void hide();
	void move(int dx, int dy);
};

#endif

