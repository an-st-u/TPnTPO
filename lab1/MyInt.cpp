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
		MyInt operator- (){ // унарный минус -A
		MyInt buf;
		buf.n=-n;
		return buf;
		}

		MyInt operator- (const MyInt& B){ // B-A
		MyInt buf;
		buf.n=n-B.n;
		return buf;
		}


		bool operator==(MyInt B){
		return (n == B.n);
		}

		bool operator>(const MyInt B){
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
				int a=n, b=B.n,c;
				c=a+b;
				//if (( c < 0xFFFF8000l) || (c > 0x00007FFFl)) {
				if (( c < INT_MIN) || (c > INT_MAX)) {  // с лонгом не сработал
				std::cout << "outOfRange +";
				//exit(1);
				}
				else {
				buf.n = n + B.n;
				}
				return buf.n;
		}
		MyInt operator/ (MyInt B){ //A/B
			MyInt buf;
			int a=n, b=B.n;
				try
					{  
					if (b == 0)
						{
						throw "Error - division by 0 "; //генерировать символьную строку
						}   
					buf.n=n / B.n;
					}
				catch(char *str)//сюда передастся строка
				{
					std::cout << str;
				}
				//buf.n=n / B.n;
				return buf;
		}

		MyInt operator* (MyInt B){ // умножение типа B*3 метод класса
			MyInt buf;
			int a=n, b=B.n,c;
			c = a * b;
			if (( c < INT_MIN) || (c > INT_MAX)) {  
				std::cout << "outOfRange *";
				}
				else {
				buf.n=n * B.n;
				}
				return buf;
		}

		friend MyInt operator+ (int m, MyInt B); // инициализациия дружественной функции
		friend void operator<<(std::ostream& os, const MyInt &B);
		friend void operator>>(std::istream& is, const MyInt &B);

		static int Test();

};// MyInt


		MyInt operator*(int m, const MyInt &B){ // бинарное умножение, тип 2*A друг класса
			MyInt buf;
			buf.m=m*B.n;
			if (( buf.m < INT_MIN) || (buf.m > INT_MAX)) {  
				std::cout << "outOfRange *";
				}
				else {
				buf.m=m * B.n;
				}
			return buf.m;
		}

		void operator<<(std::ostream& os, const MyInt &B)
		{
			os << B.n << " "<< std::endl;
		}

		void operator>>(std::istream& is, const MyInt &B)
		{
			is >> B.n;
		}

int MyInt::Test() {
	{
		MyInt A(2),B(3), C(0), ans(0),res;
		res= 2*A - B*3 + A/2 + 4; // 2*A
		//std::cout << "Example" << res ;
		if (res != ans){
			std::cout << "Error equal" ;
			//exit(1);
		}

		res = A + B;
		if (res != 5){
			std::cout << "Error operator+ : 5 not equal " << res;
			//exit(1);
		}

		res = A - B;
		if (res != -1){
			std::cout << "Error operator- " << res;
			//exit(1);
		}

		res = A * B;
		if (res != 6){
			std::cout << "Error operator* variable " << res;
			//exit(1);
		}

		res = B / A;
		if (res != 1){
			std::cout << "Error operator/ variable " << res;
			//exit(1);
		}
		res = A * 2;
		if (res != 4){
			std::cout << "Error operator A*2 " << res;
			//exit(1);
		}
		res = 2 * A;
		if (res != 4){
			std::cout << "Error operator 2*A " << res;
			//exit(1);
		}

		res = A; // эта проверка немного странная
		if(res != 2){
			std::cout << "Error operator = " << res;
		}

		if(res > A){
			std::cout <<"Error operator > " << res;
		}
	
		res= A / C;	//C=0
		
		return 0;
	}
};

void main(){
	MyInt::Test();
	MyInt A,B(2),C("5");
	MyInt *D = new MyInt();
	MyInt *E = new MyInt(10);
	A=B=C=*E;
	if (A != 10){
		std::cout << A;
	}
	delete D;
	delete E;
	//printf("Correct result");
	 _getch(); // Команда задержки экрана
	}
