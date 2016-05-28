#include "figure.h"

Figure::Figure()
{
    this->count = 0;
}

Figure::~Figure()
{
    unsigned i;
    for(i = 0; i < this->count; i++) {
        delete this->objects[i];
    }
    std::cout << i << " of " << this->count << " object(s) destroyed" << std::endl;
}

void Figure::add(Base *b)
{
    if(this->count >= 100) {
        std::cout << "maximum count of elements reached" << std::endl;
        //exit(1);
        return;
    }
    this->objects[this->count++] = b;
}

void Figure::show()
{
    for(unsigned i = 0; i < this->count; i++) {
        this->objects[i]->show();
    }
}

void Figure::hide()
{
    for(unsigned i = 0; i < this->count; i++) {
        this->objects[i]->hide();
    }
}

void Figure::move(int dx, int dy)
{
    for(unsigned i = 0; i < this->count; i++) {
        this->objects[i]->move(dx, dy);
    }

}

/*void Figure::move2(int dx2, int dy2)
	{
    for(unsigned i = 0; i < this->count; i++) {
        this->objects[i]->move(dx2, dy2);
    }
}*/

