#pragma once
#include <iostream>

class MyInt {
public: int n, m;
		MyInt();
		MyInt(int _n);
		MyInt(char *str);
		MyInt(MyInt& B);
		~MyInt();
		MyInt& operator= (const MyInt& B);
		MyInt operator-();
		MyInt operator-(const MyInt& B);
		bool operator==(const MyInt B);
		bool operator>(const MyInt B);
		bool operator<(const MyInt B);
		bool operator>=(const MyInt B);
		bool operator<=(const MyInt B);
		bool operator!=(const MyInt B);
		MyInt operator+(MyInt B);
		MyInt operator/(MyInt B);
		MyInt operator*(MyInt B);
		MyInt operator*(int m);

		friend MyInt operator*(int m, const MyInt &B);
		friend MyInt operator+ (int m, MyInt B); // объявление дружественной функции
		friend void operator<<(std::ostream& os, const MyInt &B);

};// MyInt