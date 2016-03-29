#include <iostream>
#include <conio.h>
#include "MyInt.h"
#include "MyException.h"

		//конструкторы
		MyInt::MyInt(){ 
			n=0; 
		}
		MyInt::MyInt( int n){
			this-> n=n;
		}
		//Функция sscanf() идентична функции scanf(), но данные читаются из массива,
		//адресуемого параметром buf, а не из стандартного потока ввода stdin.
		MyInt::MyInt( char *str){
			std::cout << str << n;
		}

		MyInt::MyInt(MyInt& B)
		{
			n=B.n;
		}
		
		MyInt& MyInt::operator= (const MyInt& B){
			n=B.n;
			return *this;
		}

		MyInt::~MyInt(){}
		
		MyInt MyInt::operator- (){ // унарный минус -A 
		MyInt buf;
		long long a;
		a= -n;
		if((a < INT_MIN) || (a > INT_MAX)) {
			throw new OutOfInt("-A", n, a);
		}
		buf.n = (int)a;
		return buf;
		}

		MyInt MyInt::operator- (const MyInt& B){ // B-A
			MyInt buf;
			long long c;
			c = n - B.n;
			if (( c < INT_MIN) || (c > INT_MAX)) {  // с лонгом не сработал
				throw new  OutOfInt("*" ,n, B.n, c);	
			}
			buf.n = (int)c;
			return buf;
		}

		bool MyInt::operator==(MyInt B){
			return (n == B.n);
		}

		bool MyInt::operator>(const MyInt B){
			return (n > B.n);
		}

		bool MyInt::operator< (const MyInt B){
			return (n < B.n);
		}

		bool MyInt::operator<= (const MyInt B){
			return (n <= B.n);
		}

		bool  MyInt::operator>= (const MyInt B){
			return (n >= B.n);
		}

		bool MyInt::operator!= (MyInt B){
			return (n != B.n);
		}

		MyInt MyInt::operator+ (MyInt B){ //a+B
		MyInt buf;
			long c;
			c = n+ B.n;;
			if (( c < INT_MIN) || (c > INT_MAX)) {
				throw new OutOfInt("*" ,n, B.n, c);
			}
			buf.n = c;
			return buf.n;
		}
		
		MyInt MyInt::operator/ (MyInt B){ //A/B
			MyInt buf;
			long long c;
			if(B.n == 0){
				throw new DivisionByZero(B.n);
			}else{
				c = n / B.n;
			}
			
			if(c <= INT_MIN || c >= INT_MAX)
					throw new OutOfInt("*" ,n, B.n, c);
			buf.n = (int)c;
			return buf;
		}

		MyInt MyInt::operator* (MyInt B){ // умножение типа B*A метод класса
			MyInt buf;
			long long c;
			c = n * B.n;  
			if (( c < INT_MIN) || (c > INT_MAX)) {  
				throw new OutOfInt("*" ,n, B.n, c);
			}
			buf.n=(int)c;
			return buf;
		}


		MyInt operator*(int m, const MyInt &B){ // бинарное умножение, тип 2*A друг класса
			MyInt buf;
			long long c;
			c  = m* B.n;
			if (( c < INT_MIN) || (c > INT_MAX)) {  
				throw new OutOfInt("*" ,m,B.n, c);
			}
			buf.m=(int)c;
			return buf.m;
		}

		MyInt MyInt::operator*(int m){ // бинарное умножение, тип A*2 друг класса
			MyInt buf;
			long long c;
			c  = m * n;
			if (( c < INT_MIN) || (c > INT_MAX)) {  
				throw new OutOfInt("*" ,m,n, c);
			}
			buf.n=(int)c;
			return buf.n;
		}

		void operator<<(std::ostream& os, const MyInt &B)
		{
			os << B.n << " "<< std::endl;
		}
