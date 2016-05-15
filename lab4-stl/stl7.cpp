#define _CRT_SECURE_NO_WARNINGS

//7. Для набора целых чисел из текстового файла построить упорядоченный
//список всех встречающихся значений, найти их частоты. Результаты вывести
//на консоль.


#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

void readFromFile(string pathToFile);  //считывания с файла
void showAllCompElement(int element) {cout << element << ' ';}   //вывод всех элементов вектора на консоль
bool comparisionFunc(const int elem1, const int elem2); //сревнение строк
void getFreq(int element);  //подсчитывает частоту значений
void showAllFreqElement();  //выводит отображнения

list<int> listInt;
map<int,int> valueAndFreq;

int main()
{
    readFromFile("С\\int.txt");                     //!!путь
    listInt.sort();
    cout << "Отсортированный список: ";
    for_each(listInt.begin(),listInt.end(),showAllCompElement);
    cout<<endl;
    for_each(listInt.begin(),listInt.end(),getFreq);
    showAllFreqElement();
    return 0;
}

void readFromFile(string pathToFile)
{
    ifstream fileIn;
    fileIn.open(pathToFile);
    if (fileIn.is_open())
    {
        istream_iterator<int> iterBegin(fileIn), iterEnd;
        copy(iterBegin, iterEnd, back_inserter(listInt));
        fileIn.close();
    }
    else
    {
        cout << "Can't open file "+pathToFile;
    }
}

bool comparisionFunc (const int elem1, const int elem2)
{
    return elem1<elem2;
}

void getFreq(int element)
{
    valueAndFreq[element]=count(listInt.begin(),listInt.end(),element);
}

void showAllFreqElement()
{
    map<int,int>::iterator iterMap;
    for(iterMap=valueAndFreq.begin();iterMap!=valueAndFreq.end();iterMap++)
        cout<<"Value: "<<iterMap->first<< '\t'<<"Count: "<<iterMap->second<<endl;
}
