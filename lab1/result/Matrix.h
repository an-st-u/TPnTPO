#pragma once
#include <iostream>
#include "vector.h"

class Matrix {
private:
	int M, N;
	float **A;
public:
	Matrix() { //по умолчанию
		M = N = 0; A = NULL;
	}
	Matrix(int, int); // иниц
	Matrix(int, int, float*); //иниц
	Matrix(Matrix& V);//копии
	Matrix operator-();
	float* operator[](int); // ярик
	Matrix& operator= (Matrix& V);
	Matrix operator+(Matrix& V);
	Matrix operator-(Matrix& V);
	Matrix operator*(float x);
	Vector operator*(Vector& x);
	~Matrix();

	friend void operator<<(std::ostream& os, const Matrix &V);
	friend Matrix operator*(int t, Matrix &V);

};// Matrix

