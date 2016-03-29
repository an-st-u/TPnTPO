#pragma once
class MyException {
public:
    virtual void what() = 0;
};

class OutOfRange : public MyException {
private:
	int j, Dim;

public:
	int left, right;
	char* operat;
	OutOfRange();
	OutOfRange(int,int);
	OutOfRange(char* , int, int);
	void what();
	~OutOfRange();
};

class OutOfFloat : public MyException {
private:
	float a,b;
	double c;
	char *ch;
public:
	OutOfFloat();
	OutOfFloat(char*, float, float, double);
	OutOfFloat(char*, float, int, double);
	void what();
	~OutOfFloat();
};

class ErrorInDim : public MyException {
private:
	int a, b;
public:
	ErrorInDim();
	ErrorInDim(int, int);
	void what();
	~ErrorInDim();
};

class EmptyMatrix : public MyException {
public:
	EmptyMatrix();
	void what();
	~EmptyMatrix();
};

class DivisionByZero  {
	public: 
		int num;
		DivisionByZero(int _num);
};


class OutOfInt : public MyException {
private:
	int a, b;
	long long c;
	char *ch;
public:
	OutOfInt();
	OutOfInt(char*, int, int, long long);
	OutOfInt(char*, int, long long);
	void what();
	~OutOfInt();
};

