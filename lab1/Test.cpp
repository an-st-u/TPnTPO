#include <iostream>
#include <cstdlib> // Для работы с функцией system()
#define MAX 2147483647.0
#define MIN -2147483648.0
#include "Matrix.h"
#include "Exceptions.h"

int Matrix::Test()
{
		float x[][4]={{3, 5, 2, 7}, {3, 5, 2, 6}};
		float y[][4]={{1, 1, 1, 1}, {0, 0, 0, 0}};
		Matrix A(2, 4, (float*)x), B(2, 4, (float*)y);
		Matrix C(2, 4);
		C = -A+2*A-A+B*2;
	//C[0][0] = 100;
	//[6][0] = 1; //ошибка!!
	std::cout << C;
	{
		float x[][4]={{MIN, MAX, MAX, MAX}, {MAX, MAX, MAX, MAX}};
		float y[][4]={{1, 1, MAX, 1}, {0, 0, 0, 0}};
		Matrix A(2, 4, (float*)x), B(2, 4, (float*)y);
		Matrix C(2, 4);
		try{
			C = A-B;
			//C[0][0] = 100;
			//C[6][0] = 1;   //ошибка!!
			}
			catch(OutOfRange *e){
				//printf("size problem with %d and %d\n",e->a, e->b);
				std::cout << e->operat <<" OutOfRange\n";
			}
	}

	return 0;
}


int  main()
{
	Matrix::Test();
	/*использование класса вектора
	//float z[]={0, 0, 0, 1};
	//Vector D(sizeof(z), z), R(2);
	//R=A*D;
	cout << R;*/
	system("pause");
    return 0;
}
