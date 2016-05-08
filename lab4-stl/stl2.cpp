#include <iostream> 
#include <vector> 
#include <conio.h> 
#include <iterator> 
#include <algorithm> 
#include <numeric> 
#include <fstream> 

using namespace std; 

double show(double i) //Функция, которая будет передаваться в алгоритм 
{ 
i = pow(i,2); 
return i; 
} 

void main() 
{ 

/*ifstream in; 
in.open("D:\\Универ\\6 семестр\\ТПОиТП\\лаб_4\\forN2.txt");; 
double mass2[10]; 
int i = 0; 
//while (in.eof()) 
if (!in.fail()) 
{ 
istream_iterator<double> file_it(in),end_of_stream; 
vector<double> v3; 
copy(file_it,end_of_stream,back_inserter(v3)); 
copy(v3.begin(),v3.end(),ostream_iterator<double>(cout," "); 
} 
for (int i=0;i < 10; i++) 
cout « mass2[i] « " " «endl; 
cout « "============" « endl;*/ 
double mass[] = {1, 3, 5 , 2 , 3.1, 1.1, 3.5, 17.9, 1.2, 3.1}; 
vector <double> v1; 
vector <double>::iterator it; 
vector <double> v2(mass, mass+10); 
std::sort(v2.begin(),v2.end()); 
v1 = v2; 
for_each(v1.begin(),v1.end(), v1 = show); 
copy(v1.begin(),v1.end(),ostream_iterator<double>(cout," ")); 
cout « endl; 
copy(v2.begin(),v2.end(),ostream_iterator<double>(cout," ")); 
double total; 
total = accumulate(v1.begin(), v1.end(), 0.0); 
cout « endl « "============" « endl; 
cout « "sum v1 = "« total « " "; 
total = accumulate(v2.begin(), v2.end(), 0.0); 
cout « "sum v2 = "« total; 
cout « endl; 
_getch(); 
}
