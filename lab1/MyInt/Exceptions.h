class DivisionByZero
{
	public: 
		int num;
		DivisionByZero(int _num);
};


class OutOfRange {
	public:
		int left;
		int right;
		char* operat;
		OutOfRange(char* _operat, int _left, int _right);
};

class OutOfRangeUnar {
	public:
		int number;
		char* operat;
		OutOfRangeUnar(char* _operat, int _number);
};
