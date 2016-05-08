#include <algorithm>// sort
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <conio.h>
#include <numeric>

using namespace std;

bool op(double elem1, double elem2) {
    
    return elem1 > elem2;

}

int main() {

    //vector<double> lines; // создаем строковый дек, работа как в векторе
    list<double> lines; // создаем список список
    ifstream in("C:\\forN2.txt");
    if (!in.fail()) {
        istream_iterator<double> file_it(in), end_of_stream;
        copy(file_it, end_of_stream, back_inserter(lines));
    }
    in.close();

    lines.sort(op);
    //sort(lines.begin(), lines.end(), op); // сортируем контейнер
                                      // и записываем отсортированный контейнер в новый файл
    ofstream out_file("C:\\text52.txt", ios::out); //открыть для записи
    ostream_iterator<double> file_out(out_file, " ");
    copy(lines.begin(), lines.end(), file_out);
    out_file.close();
    copy(lines.begin(), lines.end(), ostream_iterator<double>(cout, " "));
    cout << endl;
    cout << "quantity: "<< lines.size() << endl;
    cout << "average: " << accumulate(lines.begin(), lines.end(), 0.0) /lines.size() << endl;
    double n = *max_element(lines.begin(), lines.end()) - *min_element(lines.begin(), lines.end());
    cout << "range: " << n << endl;
    _getch();
    return 0;
}
