#include "figure.h"

Figure::Figure()
{

	this->objects = new Base*[MAX_FIGURES_COUNT];
	this->count = 0;
}

Figure::Figure(int quan)
{

	this->objects = new Base*[quan];
	this->count = 0;
}

Figure::~Figure()
{
	unsigned i;
	for (i = 0; i < this->count; i++) {
		delete this->objects[i];
	}
	std::cout << i << " of " << this->count << " object(s) destroyed" << std::endl;
}

void Figure::add(Base *b)
{
	if (this->count >= 100) {
		std::cout << "maximum count of elements reached" << std::endl;
		return;
	}
	this->objects[this->count++] = b;
}

void Figure::show()
{
	for (unsigned i = 0; i < this->count; i++) {
		this->objects[i]->show();
	}
}

void Figure::hide()
{
	for (unsigned i = 0; i < this->count; i++) {
		this->objects[i]->hide();
	}
}

void Figure::move(int dx, int dy)
{
	for (unsigned i = 0; i < this->count; i++) {
		this->objects[i]->move(dx, dy);
	}
}
