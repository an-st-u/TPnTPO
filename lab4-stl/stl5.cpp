#include <algorithm>// sort
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <conio.h>

using namespace std;


int main() {

    //deque<string> lines; // создаем строковый дек, работа как в векторе
    list<string> lines; // создаем список список
    ifstream in("C:\\text51.txt");
    if (!in.fail()) {
        istream_iterator<string> file_it(in), end_of_stream;
        copy(file_it, end_of_stream, back_inserter(lines));
    }
    in.close();

    lines.sort(); // сортируем контейнер
                                      // и записываем отсортированный контейнер в новый файл
    ofstream out_file("C:\\text52.txt", ios::out); //открыть для записи
    ostream_iterator<string> file_out(out_file, "\n");
    copy(lines.begin(), lines.end(), file_out);
    out_file.close();
    copy(lines.begin(), lines.end(), ostream_iterator<string>(cout, "\n"));
    _getch();
    return 0;
}
