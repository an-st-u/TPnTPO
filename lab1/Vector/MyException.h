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
public:
	OutOfFloat();
	OutOfFloat(float, float, double);
	OutOfFloat(float, int, double);
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

