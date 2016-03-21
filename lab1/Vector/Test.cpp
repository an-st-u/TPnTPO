#include "Test.h"
#include "Vector.h"
#include "MyException.h"
#include <iostream>

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
