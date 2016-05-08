#include <algorithm>// sort
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <conio.h>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	ifstream in_file; // для чтения
	in_file.open("D:\\text1.txt", ios::in);
// Создать новый как  двоичный для записи  и чтения  
	in_file.close();
	
	ofstream out_file("D:\\text2.dat", ios::out| ios_base::binary);  	// Открытие двоичного файла для записи
	out_file.close();
	_getch();
	return 0;
}


/*
9. Организовать формирование двоичного файла из имеющегося текстового. Решить предыдущую задачу для двоичного файла.

Ликбез по двоичным файлам:

Обычно различают текстовые и двоичные файлы. Текстовые файлы состоят из строк, которые завершаются символом конца строки.
В программе на С++ этот символ обозначается как '\n'.

ПРИМЕЧАНИЕ
В системе Windows строки в текстовом файле завершаются комбинацией двух байтов 0x0D0A, поэтому при операциях ввода-вывода система выполняет 
преобразование.

Обычно операции обмена с текстовым файлом сопровождаются преобразованием информации аналогично тому, как это происходит 
для стандартных потоков. По нашей классификации, приведенной в начале главы, текстовые файлы являются форматируемыми.
Форматирование не выполняется только в том случае, если содержимое текстового файла обрабатывается именно как символы и строки.

Двоичные файлы не разбиваются на строки, и никаких преобразований при обмене не выполняется — двоичные файлы не являются форматируемыми. 
Это, во-первых, означает, что операции обмена для двоичных файлов выполняются быстрее. 
Во-вторых, при операции записи в двоичный файл попадает ровно столько байтов, сколько записываемый объект занимает в памяти. 
Например, целое число, записанное в двоичный файл, займет на диске sizeof(int) байтов. 
Это существенно отличается от записи в текстовый файл, где количество записываемых по умолчанию символов зависит от величины числа. 
Например, число 12 в текстовом файле займет 2 или 3 байта (в зависимости от того, выводится ли число со знаком или без него), 
а 123 456 — 6 или 7 байт. Примером двоичного файла является исполняемый файл (с расширением exe).
*/
