#include <iostream>
#include <conio.h>

class MyInt {
public: int n, m;
		//конструкторы
		MyInt(){ 
			n=0; 
		}
		MyInt( int n){
			this-> n=n;
		}
		//Функция sscanf() идентична функции scanf(), но данные читаются из массива,
		//адресуемого параметром buf, а не из стандартного потока ввода stdin.
		MyInt( char *str){
			sscanf(str,"%d", &n);
		}
		MyInt(MyInt& B)
		{
			n=B.n;
		}
		~MyInt(){}
		MyInt& operator= (const MyInt& B){
			n=B.n;
			return *this;
		}
		MyInt operator- (MyInt B){ // унарный минус
		MyInt buf;
		buf.n=-n;
		return buf;
		}

		/*MyInt operator+ (MyInt B){ // унарный плюс
		MyInt buf;
		buf.n=n;
		return buf;
		}*/

		MyInt operator==(const MyInt B){
		return (n == B.n);
		}

		MyInt operator>(const MyInt B){
	return (n > B.n);
		}

		MyInt operator< (const MyInt B){
	return (n < B.n);
		}

		MyInt operator<= (const MyInt B){
		return (n <= B.n);
		}

		MyInt operator>= (const MyInt B){
	return (n >= B.n);
		}

		bool operator!= (MyInt B){
		return (n != B.n);
		}

		MyInt operator+ (MyInt B){ //a+B
			MyInt buf;
				long a=n, b=B.n,c;
				c=a+b;
				if (( c < 0xFFFF8000l) || (c > 0x00007FFFl)) {
				//if (( c < -100000) || (c > 100000)) {
				printf("Выход за диапазон");
				exit(1);
				}
				else {
				buf.n = n+B.n;
				return buf;
				}
		}
		MyInt operator/ (MyInt B){ //A/B
			MyInt buf;
			int a=n, b=B.n;
			if (b == 0){
			printf("Деление на ноль");
			}
			// возможно придется дописать выход за диапазон типа
			else{
				buf.n=n / B.n;
				return buf;
			}
		}

		MyInt operator* (MyInt B){ // умножение типа B*3 метод класса
			MyInt buf;
			int a=n, b=B.n;
			// возможно придется дописать выход за диапазон типа
				buf.n=n * B.n;
				return buf;
		}

		friend MyInt operator+ (int m, MyInt B); // инициализациия дружественной функции

		int Test();

};// MyInt

		MyInt operator* (int m, MyInt B){ // бинарное умножение, тип 2*A друг класса
		MyInt buf;
		buf.m=m*B.n;
		return buf;
	
		}

int MyInt::Test() { //После двух таких функций код будет нечитаем
	{
		MyInt A(2),B(3), ans(5),res;
		res = A + B;
		res= 2*A - B*3 + A/2 + 4;
		if (res != ans){
			printf ("Error");
		}
		else {
			printf("Correct result");	
		}
		return 0;
	}
};

void main(){
	MyInt A,B(2),C("5");
	MyInt *D = new MyInt();
	MyInt *E = new MyInt(10);
	A=B=C=*E;
	delete D;
	delete E;
	int Test();
	printf("Correct result");
	_getch();
	}

