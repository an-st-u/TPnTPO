#ifndef BASE_H
#define BASE_H

class Base
{
public:
    virtual void hide()=0;
    virtual void show()=0;
    virtual void move(int dx, int dy)=0;
    virtual ~Base() {}
};

#endif
