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

bool op(int elem1, int elem2) {
    
    return elem1 > elem2;

}


int main() {

    //vector<double> lines; // создаем строковый дек, работа как в векторе
    list<int> lines; // создаем список список
    ifstream in("C:\\text_int.txt",ios::in); //ios::binary - бинарное открытие,ios::in - операции ввода
    ofstream out_file("C:\\text_binary.dat", ios_base::binary);
    
    int d;
    while (true) {

        in >> d;
        if (in.fail()) { break; }
        out_file.write((char*)&d, sizeof(int));
        
    }

    in.close();
    out_file.close();
    
    in.open("C:\\text_binary.dat", ios::in | ios_base::binary);
    while (true) {
        
        in.read((char*)&d, sizeof(int));
        if (in.fail()) { break; }
        lines.push_back(d);
    }
    in.close();

    lines.sort(op);
    //sort(lines.begin(), lines.end(), op); // сортируем контейнер
                                      // и записываем отсортированный контейнер в новый файл
    out_file.open("C:\\text52.txt", ios::out); //открыть для записи
    ostream_iterator<int> file_out(out_file, " ");
    copy(lines.begin(), lines.end(), file_out);
    out_file.close();
    copy(lines.begin(), lines.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "quantity: "<< lines.size() << endl;
    cout << "average: " << accumulate(lines.begin(), lines.end(), 0.0) / lines.size() << endl;
    int n = *max_element(lines.begin(), lines.end()) - *min_element(lines.begin(), lines.end());
    cout << "range: " << n << endl;
    _getch();
    return 0;
}
