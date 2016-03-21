#include "MyException.h"
#include <iostream>


OutOfRange::OutOfRange(){}
OutOfRange::~OutOfRange(){}

OutOfRange::OutOfRange(int j, int Dim) {
	this->j = j;
	this->Dim = Dim;
}

void OutOfRange::what() {

	std::cout << std::endl <<"Out of range. " << j << " <0 or >" << Dim << std::endl;

}

ErrorInDim::ErrorInDim() {}
ErrorInDim::~ErrorInDim() {}
ErrorInDim::ErrorInDim(int a, int b) {
	this->a = a;
	this->b = b;
}

void ErrorInDim::what() {

	std::cout << "Error in dimensions." << a << "!=" << b << std::endl;
}


OutOfFloat::OutOfFloat() {}
OutOfFloat::~OutOfFloat() {}
OutOfFloat::OutOfFloat(float a, float b, double c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

OutOfFloat::OutOfFloat(float a, int d, double c) {
	this->a = a;
	this->b = (float)d;
	this->c = c;
}

void OutOfFloat::what() {

	std::cout << std::endl << "OutOfFloat. " << a << " operator " << b << " = " << c << std::endl;
	std::cout << "Error in dimensions";
}