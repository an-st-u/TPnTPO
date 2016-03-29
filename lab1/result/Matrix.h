#pragma once
#include <iostream>
#include "vector.h"

class Matrix {
private:
	int M, N;
	float **A;
public:
	Matrix() { 
		M = N = 0; A = NULL;
	}
	Matrix(int, int); 
	Matrix(int, int, float*); 
	Matrix(Matrix& V);
	Matrix operator-();
	float* operator[](int);
	Matrix& operator= (Matrix& V);
	Matrix operator+(Matrix& V);
	Matrix operator-(Matrix& V);
	Matrix operator*(float x);
	Vector operator*(Vector& x);
	~Matrix();

	friend void operator<<(std::ostream& os, const Matrix &V);
	friend Matrix operator*(int t, Matrix &V);

};// Matrix

