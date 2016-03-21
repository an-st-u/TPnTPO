#include <iostream>
#include <conio.h>
#include "MyInt.h"
#include "Exceptions.h"

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
			sscanf(str,"%d", &n);
		}
		MyInt::MyInt(MyInt& B)
		{
			n=B.n;
		}
		
		MyInt& MyInt::operator= (const MyInt& B){
			n=B.n;
			return *this;
		}
		MyInt MyInt::operator- (){ // унарный минус -A 
		MyInt buf;
		long long a=-n;
		if(a < INT_MIN || a > INT_MAX){
		throw new OutOfRangeUnar("-", a);
		}
		else
			buf.n=-n;
		return buf;
		}

		MyInt MyInt::operator- (const MyInt& B){ // B-A
		MyInt buf;
			long long a=n, b=B.n, c;
				c = a - b;
				//if (( c < 0xFFFF8000l) || (c > 0x00007FFFl)) {
				if (( c < INT_MIN) || (c > INT_MAX)) {  // с лонгом не сработал
					throw new OutOfRange("-", a, b);
				}
				else 		
					{
					buf.n = n - B.n;
					}
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
				long long a=n, b=B.n, c;
				c=a+b;
				//if (( c < 0xFFFF8000l) || (c > 0x00007FFFl)) {
				if (( c < INT_MIN) || (c > INT_MAX)) {  // с лонгом не сработал
					throw new OutOfRange("+", a, b);
				}
				else {
					buf.n = n + B.n;
					}
				return buf.n;
		}
		
		MyInt MyInt::operator/ (MyInt B){ //A/B
			MyInt buf;
			long long a=n, b=B.n, c;
			if(b == 0){
				throw new DivisionByZero(a);
				}else{
				c = n / B.n;
				}
				if(c <= INT_MIN || c >= INT_MAX)
					throw new OutOfRange("/" ,a, b);
				else
				buf.n = n / B.n;
				return buf;
		}

		MyInt MyInt::operator* (MyInt B){ // умножение типа B*3 метод класса
			MyInt buf;
			long long a=n, b=B.n,c;
			c = a * b;
			if (( c < INT_MIN) || (c > INT_MAX)) {  
				throw new OutOfRange("*" ,a, b);
				}
				else {
				buf.n=n * B.n;
				}
				return buf;
		}


		MyInt operator*(int m, const MyInt &B){ // бинарное умножение, тип 2*A друг класса
			MyInt buf;
			long long a=m, b=B.n,c;
			c  = a* b;
			if (( c < INT_MIN) || (c > INT_MAX)) {  
				throw new OutOfRange("*" ,a, b);
				}
				else {
				buf.m=m * B.n;
				}
			return buf.m;
		}

		MyInt::~MyInt(){}

		void operator<<(std::ostream& os, const MyInt &B)
		{
			os << B.n << " "<< std::endl;
		}

		void operator>>(std::istream& is, const MyInt &B)
		{
			is >> B.n;
		}
		


