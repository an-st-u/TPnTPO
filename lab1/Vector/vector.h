#pragma once
#include <iostream>

class Vector {

	private:
		int Dim;
		float *x;
	public:
		Vector() { Dim = 0; x = NULL; }
		Vector(int Dim); //конструктор инициализации
		Vector(Vector &V);
		Vector(int Dim, float x[]);
		Vector::~Vector();
		float& operator[](int j);
		Vector& operator= (const Vector& V);
		Vector operator+ (const Vector &B);
		float operator, (const Vector &B); //A,B
		Vector operator- (const Vector &B); //A-B
		Vector operator- (); //-A
		Vector operator* (const Vector &B); //A*B
		Vector operator* (int t); //B*C
	
		friend void operator<<(std::ostream& os, const Vector &V);
		friend void operator>>(std::istream& is, const Vector &V);
		friend Vector operator*(int, const Vector &V);//C*B

};