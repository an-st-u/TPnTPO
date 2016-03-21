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

		friend MyInt operator*(int m, const MyInt &B);
		friend MyInt operator+ (int m, MyInt B); // объявление дружественной функции
		friend void operator<<(std::ostream& os, const MyInt &B);
		friend void operator>>(std::istream& is, const MyInt &B);

		static int Test();
		static int Test2();

};// MyInt
