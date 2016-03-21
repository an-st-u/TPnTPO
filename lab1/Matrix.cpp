#include <iostream>
#include <cstdlib> // Для работы с функцией system()
#define MAX 2147483647.0
#define MIN -2147483648.0
#include "Matrix.h"


Matrix::Matrix (int M, int N){ // К-р инициализации
	this->M=M; this->N=N;
	A = new float*[M];
	for(int i = 0; i< M; i++)
		A[i] = new float[N];
}

Matrix::Matrix (int M, int N, float* A){ // К-р инициализации
	this->M=M; this->N=N;
	this->A = new float*[M];
	//Проверки здесь могут быть...
	for(int i = 0; i < M; i++){
		this->A[i] = new float[N];
		for (int j=0;j< N;j++) {
			this->A[i][j]= A[i*N+j];
		}
	}
}

Matrix::~Matrix(){
	for(int i=0; i<M; i++)
		free(A[i]);
	free(A);
}


Matrix::Matrix (Matrix& V){ //выделение памяти
	M=V.M;
	N=V.N;
	A = (float **)malloc(M*sizeof(float*));
	// проверка
	for(int i = 0; i< M; i++){
		A[i] = (float *)malloc(N*sizeof(float));
		// проверка
	}
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			A[i][j] = V.A[i][j];
}


Matrix& Matrix::operator-()
	{
			//float *buf = new float(M, N);
			Matrix *buf = new Matrix(M, N);
			float buff;
			for(int i = 0; i < M; ++i)
				for(int j = 0; j < N; ++j){
					buff = -A[i][j];
					buf->  A[i][j] = (float)buff;
				}
				return *buf;
	}

Matrix& Matrix::operator= (Matrix & V){
	if( M != V.M || N != V.N){
			std::cout<< "Error in dimensions";
			exit(1);
	}
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			A[i][j] = V.A[i][j];
	return *this;
}

Matrix& Matrix::operator-(Matrix & V){
			Matrix *buf = new Matrix(M, N);
			float buff;
			for(int i = 0; i < M; ++i)
				for(int j = 0; j < N; ++j){
					buff = A[i][j] - V.A[i][j];
					buf->  A[i][j] = (float)buff;
				}
			return *buf;
}

Matrix& Matrix::operator+(Matrix & V){ // сложение матриц
			Matrix *buf = new Matrix(M, N);
			float buff;
			for(int i = 0; i < M; ++i)
				for(int j = 0; j < N; ++j){
					buff = A[i][j] + V.A[i][j];
					buf->  A[i][j] = (float)buff;
				}
			return *buf;
}

Matrix& Matrix::operator*(float t){ // умножение матрицы на число A*2
	
		if(M > 0 && N > 0 && A != NULL){
			Matrix *buf = new Matrix(M, N);
			double buff;
			for(int i = 0; i < M; ++i)
				for(int j = 0; j < N; ++j){
					buff = A[i][j] * t;
					buf->  A[i][j] = (float)buff;
				}
			return *buf;
		}
		else
			std::cout<< "sizeproblem *";
}


Matrix operator*(int t, Matrix &V) // умножение числа на матрицу // бинарное умножение, тип 2*A друг класса
{
	if(V.M > 0 && V.N > 0 && V.A != NULL)
	{
		Matrix *buf = new Matrix(V.M, V.N);
		double buff;
		for(int i = 0; i < V.M; ++i)
			for(int j = 0; j < V.N; ++j)
			{
				buff = t * V.A[i][j];
				buf->  A[i][j] = (float)buff;
			}
		return *buf;
	}
	else
	{
		std::cout<< "sizeproblem *";
		exit(1);
		return V;
	}
}

void operator<<(std::ostream&os,const Matrix &V)
{
	for(int i = 0; i < V.M; i++) {
        for(int j = 0; j < V.N; j++) {
            os << V.A[i][j] << " ";
        }
       os << std::endl << std::endl;
		//return os;
	}
}
