#include "MyException.h"
#include <iostream>


OutOfRange::OutOfRange(){}
OutOfRange::~OutOfRange(){}

OutOfRange::OutOfRange(int j, int Dim) {
	this->j = j;
	this->Dim = Dim;
}

OutOfRange::OutOfRange(char* _operat, int _left, int _right){
		left = _left;
		right = _right;
		operat = _operat;

}

void OutOfRange::what() {

	std::cout << std::endl <<"Out of range. " << j << "<0 or "<< j << ">" << Dim << std::endl;

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
OutOfFloat::OutOfFloat(char *ch, float a, float b, double c) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->ch = ch;
}

OutOfFloat::OutOfFloat(char *ch, float a, int d, double c) {
	this->a = a;
	this->b = (float)d;
	this->c = c;
	this->ch = ch;
}

void OutOfFloat::what() {

	std::cout << std::endl << "OutOfFloat. " << ch 
		<< ". " << a << ", " << b << " = " << c << std::endl;
}

EmptyMatrix::EmptyMatrix() {}
void EmptyMatrix::what() {
	std::cout << "Empty Matrix";
}
EmptyMatrix::~EmptyMatrix() {}


DivisionByZero::DivisionByZero(int _num){
		num =_num;			
}

OutOfInt::OutOfInt() {}
OutOfInt::~OutOfInt() {}
OutOfInt::OutOfInt(char *ch, int a, int b, long long c) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->ch = ch;
}

OutOfInt::OutOfInt(char *ch, int a, long long c) {
	this->a = a;
	this->b = 0;
	this->c = c;
	this->ch = ch;
}


void OutOfInt::what() {

	std::cout << std::endl << "OutOfInt. " << ch 
		<< ". " << a << ", " << b << " = " << c << std::endl;
}
