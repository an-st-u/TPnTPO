#pragma once
class MyException {
public:
	virtual void what() {};
};

class OutOfRange : public MyException {
private:
	int j, Dim;

public:
	OutOfRange();
	OutOfRange(int,int);
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

