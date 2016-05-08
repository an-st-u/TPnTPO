#include <algorithm>// sort
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;


int main() {

    vector<string> lines; // создаем строковый вектор
    ifstream in("C:\\text51.txt");
    if (!in.fail()) {
        istream_iterator<string> file_it(in), end_of_stream;
        copy(file_it, end_of_stream, back_inserter(lines));
    }
    in.close();

    sort(lines.begin(), lines.end()); // сортируем контейнер
    // и записываем отсортированный контейнер в новый файл
    ofstream out_file("C:\\text52.txt", ios::out); //открыть для записи
    ostream_iterator<string> file_out(out_file,"\n");
    copy(lines.begin(), lines.end(), file_out);
    out_file.close();
    copy(lines.begin(), lines.end(), ostream_iterator<string>(cout, "\n"));
    _getch();
    return 0;
}

/*

3.Прочитать текстовый файл и поместить как string в контейнер vector. 
Отсортировать строки по алфавиту и вывести на консоль и в файл, с тем же именем и расширением srt.
4. Решить ту же задачу, используя для хранения строки класс string.
*/
