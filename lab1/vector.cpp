#include <iostream>
#include <cstdlib> // Для работы с функцией system()
#define MAX 2147483647.0
#define MIN -2147483648.0

using namespace std;

class Vector {

private:
    int Dim;
    float *x;
public:
    Vector(){Dim=0; x=NULL;}
    Vector(int Dim);
    Vector(Vector &V);
    Vector(int Dim, float x[]);
	Vector &operator[](unsigned i);
    ~Vector();

    float& operator[](int j){
        if(j < 0 || j >= Dim){
            cout << "Out of range"<<endl;
            exit(1);
        }
        return x[j];
    }

	//выход за диапазон
    Vector& operator= (const Vector& V) {
        if(Dim!=V.Dim){
            cout << "Error in dimensions";
        }
        Dim=V.Dim;
        for(int i=0; i<Dim; i++)
            x[i] = V.x[i];
        return (*this);
    }

    Vector operator+ (const Vector &B){ //A+B
        Vector buf(Dim);
        for(int i=0; i<Dim; i++)
            buf.x[i] = x[i]+B.x[i];
        return buf;
    }

    float operator, (const Vector &B){ //A,B
        Vector buf(1);
        for(int i=0; i<Dim; i++)
            buf.x[0]+= x[i]*B.x[i];
        return buf.x[0];
    }

    Vector operator- (const Vector &B){ //A-B

        Vector buf(Dim);
        for(int i=0; i<Dim; i++) {
            buf.x[i] = x[i]-B.x[i];
        }
        return buf;
    }

    Vector operator- (){ //-A

        Vector buf(Dim);
        for(int i=0; i<Dim; i++) {
            buf.x[i] = -x[i];
        }
        return buf;
    }


    Vector operator* (const Vector &B){ //A*2
        Vector buf(Dim);
        double test;
        for(int i=0; i<Dim; i++) {
            test = x[i]*B.x[i];
            if ((test < MIN) || (test > MAX)) {
              cout << "Out of range"<<endl;
              exit(1);
            }
            buf.x[i]=(float)test;
        }
        return buf;
    }

    Vector operator* (int t){ //B*C
        Vector buf(Dim);
        for(int i=0; i<Dim; i++) {
            buf.x[i] = x[i]*t;
        }
        return buf;
    }

    friend void operator<<(ostream& os, const Vector &V);
    friend Vector operator*(int, const Vector &V);

};

//конструктор инициализации
Vector::Vector(int D){
    Dim = D;
    x = new float[Dim];
};

Vector::~Vector(){
    delete[] x;
}

Vector::Vector(int Dim, float x[]) {
    this->Dim = Dim;
    this->x = new float[Dim];
    for (int i=0; i<Dim ; i++){
        this->x[i] = x[i];
    }
}

Vector::Vector (Vector &B){
    Dim=B.Dim;
    x = new float[Dim];
    for(int i=0; i<Dim; i++)
        x[i] = B.x[i];
};

Vector operator* (int t, const Vector &B){ //C*B
        Vector buf(B.Dim);
        for(int i=0; i<B.Dim; i++)
            buf.x[i] = t*B.x[i];
        return buf;
    }

void operator<<(ostream& os, const Vector &B) {
    for (int i=0;i<B.Dim;i++)
        os << B.x[i] << " ";
    os << endl;
}

class Matrix{
	public:
		int M, N;
		float **A;
		Matrix(){ //по умолчанию
			M=N=0; A=NULL;
		}
		Matrix(int _m, int _n); // иниц
		Matrix(int _m, int _n, float *_A); //иниц
		Matrix(Matrix& V);//копии
		Matrix& operator-();
		Matrix& operator= (Matrix& V); 
		Matrix& operator+(Matrix& V);
		Matrix& operator-(Matrix& V);
		Matrix& operator*(float x);
		~ Matrix ();
		Vector &operator[](unsigned i); // для FF[][]
		friend ostream& operator<<(ostream& os, Matrix V);
		friend Matrix operator*(int t, const Matrix &V);
		};

		// К-р инициализации
Matrix:: Matrix (int _m, int _n){
	M=_m;
	N=_n;
	A = (float **)malloc(M*sizeof(float*));
	// проверка выхода за диапазон
	for(int i = 0; i< M; i++){
	A[i] = (float *)malloc(N*sizeof(float));
	// проверка
	}
	};

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
};


Matrix& Matrix::operator-()
	{
			Matrix *buf = new Matrix(M, N);
			float buff;
			for(int i = 0; i < M; ++i)
				for(int j = 0; j < N; ++j)
					buff = -A[i][j];
				return *buf;
	}

Matrix& Matrix::operator= (Matrix & V){
	if( M != V.M || N != V.N){
			cout<< "Error in dimensions";
			exit(1);
	}
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			A[i][j] = V.A[i][j];
	return *this;
};

Matrix& Matrix::operator-(Matrix & V){
			Matrix *buf = new Matrix(M, N);
			float buff;
			for(int i = 0; i < M; ++i)
				for(int j = 0; j < N; ++j){
					buff = A[i][j] - V.A[i][j];
				}
			return *buf;
	}

Matrix& Matrix::operator+(Matrix & V){ // сложение матриц
			Matrix *buf = new Matrix(M, N);
			float buff;
			for(int i = 0; i < M; ++i)
				for(int j = 0; j < N; ++j){
					buff = A[i][j] + V.A[i][j];
				}
			return *buf;
	}

Matrix& Matrix::operator*(float t) // умножение матрицы на число
	{
		if(M > 0 && N > 0 && A != NULL){
			Matrix *buf = new Matrix(M, N);
			double buff;
			for(int i = 0; i < M; ++i)
				for(int j = 0; j < N; ++j){
					buff = A[i][j] * t;
				}
			return *buf;
		}
		else
			cout<< "sizeproblem *";
	}


Matrix operator*(int t, Matrix &V) // умножение числа на матрицу
{
	if(V.M > 0 && V.N > 0 && V.A != NULL){
		Matrix *buf = new Matrix(V.M, V.N);
		double buff;
		for(int i = 0; i < V.M; ++i)
			for(int j = 0; j < V.N; ++j){
				buff = t * V.A[i][j];
			}
			return *buf;
	}
				else
					cout<< "sizeproblem *";
}


int  main()
{
    float x[]={3, 5, 2, 6};
    float y[]={1, 1, 1, -1.4};
    int szf = sizeof(x)/4;
    Vector A(szf, x),B(szf, y),C(szf);
    C=-A+2*A-A+B*2;
    cout << C;
    C[0]=(A,B);
    cout << C[0] << endl;
    C[6] = 1;
	//////////
	//float x[][4]={{3, 5, 2, 6}, {3, 5, 2, 6}};
	//float y[][4]={{1, 1, 1, 1}, {0, 0, 0, 0}};
	float x1[] = {3, 5, 2, 6};
	float x2[] = {3, 5, 2, 6};
	float y1[] = {1, 1, 1, 1};
	float y2[] = {0, 0, 0, 0};
	Vector X1(4, x1);
	Vector X2(4, x2);
	Vector Y1(4, y1);
	Vector Y2(4, y2);
	Vector xx[][2] = {X1, X2};
	Vector yy[][2] = {Y1, Y2};
	Matrix AA(2, 4, (float *)xx), BB(2, 4, (float *)yy);
	Matrix F(2, 4);
	F = -AA+2*AA-AA+BB*2;
	F[0][0] = 100;
	F[6][0] = 1; //ошибка!!
	cout << F << endl;
	//использование класса вектора
	//float z[]={0, 0, 0, 1};
	//Vector D(sizeof(z), z), R(2);
	//R=A*D;
	//сout << R;
	system("pause");
    return 0;
}
