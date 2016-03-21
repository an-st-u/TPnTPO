#include <iostream>
#include <cstdlib> // Для работы с функцией system()
#define MAX 2147483647.0
#define MIN -2147483648.0
#include "Matrix.h"


int  main()
{
	float x[][4]={{3, 5, 2, 7}, {3, 5, 2, 6}};
	float y[][4]={{1, 1, 1, 1}, {0, 0, 0, 0}};
	Matrix A(2, 4, (float*)x), B(2, 4, (float*)y);
	Matrix C(2, 4);
	C = -A+2*A-A+B*2;
	//C[0][0] = 100;
	//[6][0] = 1; //ошибка!!
	std::cout << A;
	/*использование класса вектора
	//float z[]={0, 0, 0, 1};
	//Vector D(sizeof(z), z), R(2);
	//R=A*D;
	cout << R;*/
	system("pause");
    return 0;
}
