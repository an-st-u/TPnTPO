#pragma once
#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <string.h>

class Base
{
public:
    virtual void Hide() = 0;
    virtual void Show() = 0;
    virtual void Move(int dx, int dy) = 0;
    virtual void output(char* fnameo){};
};

#endif BASE_H
