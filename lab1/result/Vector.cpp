#include <cstdlib> // Для работы с функцией system()
#include "vector.h"
#include "MyException.h"
#define MAX 2147483647.0
#define MIN -2147483648.0

using namespace std;

Vector::Vector(int D) {
	Dim = D;
	x = new  float[Dim];
};

Vector::Vector(int Dim, float x[]) {
	this->Dim = Dim;
	this->x = new  float[Dim];
	for (int i = 0; i<Dim; i++) {
		this->x[i] = x[i];
	}
}

Vector::Vector(Vector &B) {
	Dim = B.Dim;
	x = new  float[Dim];
	for (int i = 0; i<Dim; i++)
		x[i] = B.x[i];
}

Vector::~Vector() {
	delete[] x;
}

float& Vector::operator[](int j) {

	if (j < 0 || j >= Dim) {
		throw &OutOfRange(j, Dim);
	}
	return x[j];
}

Vector& Vector::operator= (const Vector& V) {

	if (Dim != V.Dim) {
		throw &ErrorInDim(V.Dim, Dim);
	}
	Dim = V.Dim;

	for (int i = 0; i<Dim; i++)
		x[i] = V.x[i];
	return (*this);
}

Vector Vector::operator+ (const Vector &B) { //A+B
	if (Dim != B.Dim) {
		throw &ErrorInDim(B.Dim, Dim);
	}
	Vector buf(Dim);
	double test;
	for (int i = 0; i<Dim; i++) {
		test = (double)x[i] + (double)B.x[i];
		if ((test < MIN) || (test > MAX)) {
			throw &OutOfFloat("A+B", x[i], B.x[i],test);
		}
		buf.x[i] = (float)test;
	}
	return buf;
}

float Vector::operator, (const Vector &B) { //A,B
	if (Dim != B.Dim) {
		throw &ErrorInDim(B.Dim, Dim);
	}
	double m = 0;
	for (int i = 0; i<Dim; i++) {
		m += (double)x[i] * (double)B.x[i];
		if ((m < MIN) || (m > MAX)) {
			throw &OutOfFloat("(A,B)", x[i], B.x[i], m);
		}
	}
	return (float)m;
}

Vector Vector::operator- (const Vector &B) { //A-B
	if (Dim != B.Dim) {
		throw &ErrorInDim(B.Dim, Dim);
	}
	double test;
	Vector buf(Dim);
	for (int i = 0; i<Dim; i++) {
		test = (double)x[i] - (double)B.x[i];
		if ((test < MIN) || (test > MAX)) {
			throw &OutOfFloat("A-B", x[i], B.x[i], test);
		}
		buf.x[i] = (float)test;
	}
	return buf;
}

Vector Vector::operator- () { //-A

	Vector buf(Dim);
	for (int i = 0; i<Dim; i++) {
		buf.x[i] = -x[i];
	}
	return buf;
}

Vector Vector::operator* (const Vector &B) { //A*B
	if (Dim != B.Dim) {
		throw &ErrorInDim(B.Dim, Dim);
	}
	Vector buf(Dim);
	double test;
	for (int i = 0; i<Dim; i++) {
		test = x[i] * B.x[i];
		if ((test < MIN) || (test > MAX)) {
			throw &OutOfFloat("A*B", x[i], B.x[i], test);
		}
		buf.x[i] = (float)test;
	}
	return buf;
}

Vector Vector::operator* (int t) { //B*Const
	Vector buf(Dim);
	double test;
	for (int i = 0; i<Dim; i++) {
		test = (double)x[i] * t;
		if ((test < MIN) || (test > MAX)) {
			throw &OutOfFloat("A*Const", x[i], t, test);
		}
		buf.x[i] = (float)test;
	}
	return buf;
}

void Vector::set (int i, float a) {
	this->x[i] = a;
}

int Vector::getDim () {
	return Dim;
}

Vector operator* (int t, const Vector &B) { //C*B

	Vector buf(B.Dim);
	double test;
	for (int i = 0; i<B.Dim; i++) {
		test = t*B.x[i];
		if ((test < MIN) || (test > MAX)) {
			throw &OutOfFloat("Const*A", B.x[i], t, test);
		}
		buf.x[i] = (float)test;
	}
	return buf;
}


void operator<<(ostream& os, const Vector &B) {
	for (int i = 0; i<B.Dim; i++)
		os << B.x[i] << " ";
	os << endl;
}



