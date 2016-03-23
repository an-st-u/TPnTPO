#include <cstdlib> // // Для работы с функцией system()
#include "MyException.h"
#include "Matrix.h"
#define MAX 2147483647.0
#define MIN -2147483648.0


Matrix::Matrix(int M, int N) { // К-р инициализации
	this->M = M; this->N = N;
	A = new  float*[M];
	for (int i = 0; i< M; i++)
		A[i] = new  float[N];
}

Matrix::Matrix(int M, int N, float* A) { // К-р инициализации
	this->M = M; this->N = N;
	this->A = new  float*[M];
	//Проверки здесь могут быть...
	for (int i = 0; i < M; i++) {
		this->A[i] = new  float[N];
		for (int j = 0; j< N; j++) {
			this->A[i][j] = A[i*N + j];
		}
	}
}


Matrix::Matrix(Matrix& V) { //выделение памяти
	M = V.M;
	N = V.N;
	A = new  float*[M];
	for (int i = 0; i < M; i++) {
		A[i] = new  float[N];
		for (int j = 0; j < N; j++)
			A[i][j] = V.A[i][j];
	}
}

Matrix::~Matrix() {
	for (int i = 0; i<M; i++)
		free(A[i]);
	free(A);
}

float* Matrix::operator[](int _M) {  // ? Vector D(szf, z)

	if (_M < 0 || _M >= M) {
		throw  new OutOfRange(_M, M);
	}
	return (float*)A[_M];
}


Matrix Matrix::operator-() {

	Matrix buf(M, N);
	float buff;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			buff = -A[i][j];
			buf.A[i][j] = buff;
		}
	}
	return buf;
}

Matrix& Matrix::operator= (Matrix & V) {
	
	if (M != V.M) {
		throw &ErrorInDim(M, V.M);
		if (N != V.N) {
			throw &ErrorInDim(N, V.N);
		}
	} else {
		
		for (int i = 0; i<M; i++)
			for (int j = 0; j<N; j++)
				A[i][j] = V.A[i][j];
	}
	return *this;
}

Matrix Matrix::operator-(Matrix & V) {
	
	Matrix buf(M, N);
	double buff;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			buff = A[i][j] - V.A[i][j];
			if (buff < MIN || buff > MAX) {
				throw &OutOfFloat("A-B", A[i][j], V.A[i][j], buff);
			}
			else {
				buf.A[i][j] = (float)buff;
			}
		}
	}
	return buf;
}

Matrix Matrix::operator+(Matrix & V) { // сложение матриц
	
	Matrix buf(M, N);
	double buff;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			buff = A[i][j] + V.A[i][j];
			if (buff < MIN || buff > MAX) {
				throw &OutOfFloat("A+B", A[i][j], V.A[i][j], buff);
			}
			else {
				buf.A[i][j] = (float)buff;
			}
		}
	}
	return buf;
}

Matrix Matrix::operator*(float t) { // умножение матрицы на число A*2

	if (M == 0 || N == 0 || A == NULL) {
		throw &EmptyMatrix();
	}
	
	Matrix buf(M, N);
	double buff;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			buff = A[i][j] * t;
			if (buff < MIN || buff > MAX) {
				throw &OutOfFloat("A*Const", t, A[i][j], buff);
			}
			else {
				buf.A[i][j] = (float)buff;
			}
		}
	}
		return buf;
	
}

Vector Matrix::operator*(Vector& A) { //умножение вектора на число A*2

	int Dim = A.getDim();
	if (Dim != this->N) {
		throw &ErrorInDim(Dim, this->N);
	}
	Vector buf(this->M);
	double buff = 0;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			buff += this->A[i][j] * A[j];
			if (buff < MIN || buff > MAX) {
				throw &OutOfFloat(" A*Vector", this->A[i][j], A[j], buff);
			}	
		}
		buf.set(i, buff);
		buff = 0;
	}
	return buf;

}


Matrix operator*(int t, Matrix &V) { // умножение числа на матрицу // бинарное умножение, тип 2*A друг класса

	if (V.M == 0 || V.N == 0 || V.A == NULL) {
		throw &EmptyMatrix();
	}
	
	Matrix buf(V.M, V.N);	
	double buff;
	for (int i = 0; i < V.M; ++i) {
		for (int j = 0; j < V.N; ++j) {
			buff = t * V.A[i][j];
			if (buff < MIN || buff > MAX) {
				throw &OutOfFloat("Const*A",(float)t, V.A[i][j], buff);
			} else {
				buf.A[i][j] = (float)buff;
			}
		}
	}
	
	return buf;

}

void operator<<(std::ostream&os, const Matrix &V)
{
	for (int i = 0; i < V.M; i++) {
		for (int j = 0; j < V.N; j++) {
			os << V.A[i][j] << " ";
		}
		os << std::endl;
	}
	os << std::endl;
}
