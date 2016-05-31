#pragma once
#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include "Base.h"
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
};

#endif

