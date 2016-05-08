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

    
    double mass[] = { 1, 3, 5 , 2 , 3.1, 1.1, 3.5, 17.9, 1.2, 3.1 };
    
    vector <double> v1(mass, mass + 10);
    vector <double> v2;
    std::sort(v1.begin(), v1.end());
    copy(v1.begin(), v1.end(), back_inserter(v2));
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

