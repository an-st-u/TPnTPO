#include "Test.h"
#include <conio.h>
#include <iostream>

int  main() {

	Test::MyIntTest();
	Test::MyIntTest2();
	std::cout << "   "<< std::endl;
	Test::TestVector();
	Test::TestMatrix();
	Test::MyIntTest3();
	_getch();
	return 0;

}
