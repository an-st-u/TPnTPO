#include <cstdio>
#include <conio.h>
#include <iostream>
#include "MyInt.h"
#include "Exceptions.h"

int MyInt::Test() {
		MyInt A(2),B(3), ans(0),res, C(1), D(0), F(0);
		//MyInt A(15), B(INT_MAX-1), C(0), D(INT_MIN+1), res;
		//long F(INT_MAX+14);

		res= 2*A - B*3 + A/2 + 4; 
		std::cout << "Answer = " << res;

		if (res != ans){
			std::cout << "Error: it is not equal 10 "<< std::endl ;
			//exit(1);
		}

		res = A + B;
		if (res != 5){
			std::cout << "Error operator+ : 5 not equal " << res;
			//exit(1);
		}

		res = A - B;
		if (res != -1){
			std::cout << "Error operator- : -1 not equal " << res;
			//exit(1);
		}

		res = A * B;
		if (res != 6){
			std::cout << "Error operator* binar : 6 not equal " << res;
			//exit(1);
		}

		res = B / A;
		if (res != 1){
			std::cout << "Error operator/ binar : 1 not equal " << res;
			//exit(1);
		}
		res = A * 2;
		if (res != 4){
			std::cout << "Error operator A*2 : 4 not equal " << res;
			//exit(1);
		}
		res = 2 * A;
		if (res != 4){
			std::cout << "Error operator 2*A : 4 not equal " << res;
			//exit(1);
		}

		res = A; // эта проверка немного странная
		if(res != 2){
			std::cout << "Error operator = : 2 not equal " << res;
		}

		res = -A; // эта проверка немного странная
		if(res != 2){
			std::cout << "Error operator = : 2 not equal " << res;
		}

		if(res > A){
			std::cout <<"Error operator > : 2 not more " << res;
		}

		try {
			res= A / C;
			}
			catch(DivisionByZero* e)
				{
				std::cout <<  e->num <<" division by zero\n";
				}

		try{
			res= A+B;
			}
			catch(OutOfRange* e)
				{
				std::cout << e->operat <<" OutOfRange\n";
				}

		try{
			res= A*B;
			}
			catch(OutOfRange* e)
				{
				std::cout << e->operat <<" OutOfRange\n";
				}

		try{
			res= 2*A;
			}
			catch(OutOfRange* e)
				{
				std::cout << e->operat <<" OutOfRange\n";
				}

		try{
			res= A-B;
			}
			catch(OutOfRange* e)
				{
				std::cout << e->operat <<" OutOfRange\n";
				}
	
	
		try{ // не работает
			res= -F;
			}
			catch(OutOfRangeUnar* e)
				{
				std::cout << e->operat <<" OutOfRangeUnar\n";
				}

		return 0;
};

int MyInt::Test2(){
	MyInt A,B(2),C("5");
	MyInt *D = new MyInt();
	MyInt *E = new MyInt(10);
	A=B=C=*E;
	if (A != 10){
		std::cout << "10 no equal "<< A;
	}
	delete D;
	delete E;
	return 0;
}

void main(){
	MyInt::Test();
	MyInt::Test2();
	_getch(); // Команда задержки экрана
	}
