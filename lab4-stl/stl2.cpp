#include <iostream>
#include <vector>
#include <conio.h>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

void vin(double &elem) {

   elem = pow(elem, 2);

}

void main() {

    double mass[10];
    int _size = sizeof(mass) / sizeof(double);
    
    ifstream in;
    in.open("C:\\forN2.txt");
    if (!in.fail()) {
        istream_iterator<double> file_it(in), end_of_stream;
        copy(file_it, end_of_stream, mass);
    }
    
    vector <double> v1(mass, mass + _size);
    vector <double> v2(_size);
    std::sort(v1.begin(), v1.end());
    copy(v1.begin(), v1.end(), v2.begin());
    for_each(v2.begin(), v2.end(), vin);
    copy(v1.begin(), v1.end(), ostream_iterator<double>(cout, " "));
    cout << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<double>(cout, " "));
    cout << endl;
    double total;
    total = accumulate(v1.begin(), v1.end(), 0.0);
    cout << endl << "============" << endl;
    cout << "sum v1 = " << total << " ";
    total = accumulate(v2.begin(), v2.end(), 0.0);
    cout << "sum v2 = " << total;
    cout << endl;
    _getch();
}

