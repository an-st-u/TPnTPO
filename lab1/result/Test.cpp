#include "Test.h"
#include "Vector.h"
#include "Matrix.h"
#include "MyException.h"
#include <iostream>
#define MAX 2147483647.0
#define MIN -2147483648.0

using namespace std;
Test::Test(){}
Test::~Test(){}
void Test::TestVector() {

	try {
		float x[] = { 3, 5, 2, 6 };
		float y[] = { 1, 1, 1, -1.4 };
		int szf = sizeof(x) / 4;
		Vector A(szf, x), B(szf, y), C(szf);
		C = -A + 2 * A - A + B * 2;
		cout << C;
		cout << "A = " << A;
		cout << "B = " << B;
		cout << "A + B = " << A + B;
		cout << "A - B = " << A - B;
		cout << "A * B = " << A * B;
		cout << "A * 2 = " << A * 2;
		cout << "-A = " << -A;
		C[0] = (A, B);
		cout << "(A,B) = " << C[0];
		C[6] = 1;
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
		float c[][4] = { { MIN, MAX, MAX, MAX },{ MAX, MAX, MAX, MAX } };
		float d[][4] = { { 1, 1, MAX, 1 },{ 0, 0, 0, 0 } };
		Matrix A(2, 4, (float*)x), B(2, 4, (float*)y);
		Matrix C(2, 4);
		C = -A + 2 * A - A + B * 2;
		cout << C;
		C[0][0] = 100;
		
		try {
			C[8][0] = 1; //ошибка!!
		} catch (MyException *e) {
			e->what();
		}
		
		float z[] = { 0, 0, 0, 1 };
		int szf = sizeof(z) / 4;
		Vector D(szf, z), R(2);
		R = A*D;
		cout << R;

		float a[][4] = { { MIN, MAX, MAX, MAX },{ MAX, MAX, MAX, MAX } };
		float b[][4] = { { 1, 1, MAX, 1 },{ 0, 0, 0, 0 } };
		Matrix An(2, 4, (float*)a), Bn(2, 4, (float*)b);
		Matrix Cn(2, 4);
		Cn = An + Bn;

	}
	catch (MyException *e) {
		e->what();
	}catch (...) {
		cout << "unexpected error";
	}
}
