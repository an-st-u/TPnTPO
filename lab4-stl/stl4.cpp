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
	string s;
	vector<string> lines; // создаем строковый вектор

	// читаем файл в контейнер построчно
	ifstream in_file("D:\\text1.txt", ios::in); // для чтения
	while(getline(in_file, s)) // до конца строки
		lines.push_back(s); //Для добавления нового элемента в конец вектора используется метод push_back()
	in_file.close();

	sort(lines.begin(), lines.end()); // сортируем контейнер

	// и записываем отсортированный контейнер в новый файл
	vector<string>::iterator i = lines.begin();
	ofstream out_file("D:\\text2.txt", ios::out); //открыть для записи
	for(i; i != lines.end(); ++i){
		out_file << *i << endl;
		cout << *i << endl;
	}
	out_file.close();
	_getch();
	return 0;
}

/*

3.Прочитать текстовый файл и поместить как string в контейнер vector. 
Отсортировать строки по алфавиту и вывести на консоль и в файл, с тем же именем и расширением srt.
4. Решить ту же задачу, используя для хранения строки класс string.
*/
