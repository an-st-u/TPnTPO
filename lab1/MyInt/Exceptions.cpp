#include "Exceptions.h"

DivisionByZero::DivisionByZero(int _num){
		num =_num;			
}

OutOfRange::OutOfRange(char* _operat, int _left, int _right){
		left = _left;
		right = _right;
		operat = _operat;

};

OutOfRangeUnar::OutOfRangeUnar(char* _operat, int _number){
	number = _number;
	operat = _operat;
}
