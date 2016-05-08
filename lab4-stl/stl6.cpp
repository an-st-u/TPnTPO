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
	string s;
	vector<string> lines; // создаем строковый вектор
	// читаем файл в контейнер построчно
	ifstream in_file("D:\\text1.txt", ios::in); // для чтения
	cout << "Исходный файл:"  << endl;
	int n = 0;
	while(getline(in_file, s)){ // до конца строки
		n += 1;
		int word = 0;
        int flag = 0;
		cout << s << endl;
		int size = s.size();
		cout << "Количество символов в " << n <<" строке = " << size << endl;
        for (int j = 0; j < size; j++) 
            if (s[j] != ' ' && flag == 0) {
                word += 1;
                flag = 1;
            } 
			else if (s[j] == ' ') 
				flag = 0;
		cout << "слов  = " << word << endl;
		lines.push_back(s);  //Для добавления нового элемента в конец вектора используется метод push_back()
	}
	cout << "Количество строк в исходном файле = " << n << endl;
	
	in_file.close();
	sort(lines.begin(), lines.end()); // сортируем контейнер

	// и записываем отсортированный контейнер в новый файл
	vector<string>::iterator i = lines.begin();
	ofstream out_file("D:\\text2.txt", ios::out); //открыть для записи
	cout << "===============================================" << endl;
	cout << "Измененный файл:"  << endl;
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
6. В предыдущей задаче найти количество символов, слов и строк в текстовом файле. Вывести отчет на консоль.
*/

