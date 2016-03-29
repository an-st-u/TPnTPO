#include "Test.h"
#include <cmath>
#include "MyInt.h"
#include "Vector.h"
#include "Matrix.h"
#include "MyException.h"
#include <iostream>
#define MAX 2147483647.0
#define MIN -2147483648.0

using namespace std;
Test::Test(){}
Test::~Test(){}

void Test::MyIntTest() {

		
		MyInt A(2),B(3), ans(0),res, C(1), D(0), F(INT_MIN);
		//MyInt A(15), B(INT_MAX-1), C(0), D(INT_MIN+1), res;
		//long F(INT_MAX+14);
		try {
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
		if(res != -2){
			std::cout << "Error operator = : -2 not equal " << res;
		}

		if(res > A){
			std::cout <<"Error operator > : 2 not more " << res;
		}
		} catch (MyException* e) {
			e->what();
		}

		try {
			res= A / C;
		}
		catch(DivisionByZero* e){
				std::cout <<  e->num <<" division by zero\n";
		}

		try{
			res= A+B;
		}
		catch(MyException* e){
			e->what();
		}

		try{
			res= A*B;
		}
		catch(MyException* e){
			e->what();
		}

		try{
			res= 2*A;
		}
		catch(MyException* e){
			e->what();
		}

		try{
			res= A-B;
		}
		catch(MyException* e){
			e->what();
		}

		


};

void Test::TestMyInt() {

	MyInt A(2),B(3),res;
	int result_int;
	res=-2*A+B*7-A*A*B;
	
	{
		int A(2),B(3);
		result_int=-2*A+B*7-A*A*B;
	}
	
	if (res!= result_int) {
		cout << "Expression error - " << result_int << "not equal" << res;
	}

	A = -78, B = 3594, res;
	res = -A + 548 * B + B / 113 * B + 4 * A * B - 54 + A * 48 - A;

	{
		int A(-78), B(3594);
		result_int = -A + 548 * B + B / 113 * B + 4 * A * B - 54 + A * 48 - A;
	}

	if (res != result_int) {
		cout << "Expression error : " << result_int << " not equal " << res;
	}

}


void Test::TestVector() {

	try {
		float x[] = { 3, 5, 2, 6 };
		float y[] = { 1, 1, 1, -1.4 };
		int szf = sizeof(x) / 4;
		Vector A(szf, x), B(szf, y), C(szf);
		C = -A + 2 * A - A + B * 2;
		float t[] = { 2, 2, 2, -2.8 };
		Vector Test(szf, t);

		if (C != Test) {
			cout << "Expression error : " << C;
			cout << "not equal : " << Test;
		}

        C[0] = (A, B); 
        float a = 1.6;
        if (abs(C[0] - a) > 0.001) {

            cout << "Expression error : " << C[0];
            cout << " not equal : " << a;
            cout << endl;
            
        }
		
		try {
			C[6] = 1;
			std::cout << "We waited exceptions" << std::endl;
		}
		catch (MyException *e) {
		}
		

	}catch (MyException *e) {
		e->what();	
	}catch (...) {
		cout << "unexpected error";
	}

}

void Test::TestMatrix() {
	try {

		float x[][4] = { { 3, 5, 2, 6 },{ 3, 5, 2, 6 } };
		float y[][4] = { { 1, 1, 1, 1 },{ 0, 0, 0, 0 } };
		Matrix A(2, 4, (float*)x), B(2, 4, (float*)y);
		Matrix C(2, 4);
		C = -A + 2 * A - A + B * 2;
		C[0][0] = 100;
		
		try {
			C[8][0] = 1;
			std::cout << "We waited exceptions" << std::endl;
		} catch (MyException *e) {
		} 
		
		float z[] = { 0, 0, 0, 1 };
		int szf = sizeof(z) / 4;
		Vector D(szf, z), R(2);
		R = A*D;

		float a[][4] = { { MIN, MAX, MAX, MAX },{ MAX, MAX, MAX, MAX } };
		float b[][4] = { { 1, 1, MAX, 1 },{ 0, 0, 0, 0 } };
		Matrix An(2, 4, (float*)a), Bn(2, 4, (float*)b);
		Matrix Cn(2, 4);
		
		try {
		Cn = An + Bn;
		std::cout << "We waited exceptions" << std::endl;
		}
		catch (MyException *e) {
		}

	}
	catch (MyException *e) {
		e->what();
	}catch (...) {
		cout << "unexpected error";
	}
}
