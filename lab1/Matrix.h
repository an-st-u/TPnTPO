class Matrix{
	public:
		int M, N;
		float **A;
		Matrix(){ //по умолчанию
			M=N=0; A=NULL;
		}
		Matrix(int _m, int _n); // иниц
		Matrix(int _m, int _n, float* _A); //иниц
		Matrix(Matrix& V);//копии
		Matrix& operator-();
		Matrix& operator= (Matrix& V);
		Matrix& operator+(Matrix& V);
		Matrix& operator-(Matrix& V);
		Matrix& operator*(float x);
		~ Matrix ();
		
		friend void operator<<(std::ostream& os,const Matrix &V);
		friend Matrix operator*(int t, Matrix &V);

		static int Test();
};// Matrix
