#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstring>


using namespace std;

vector<char*> readFromFile(string pathToFile);  //считывания с файла
void insertInVectorChar(string str);    //перевод из vector<string> в vector<char>
bool comparisionFunc(const char *str1, const char *str2); //сревнение строк
void showAllStr(char *str) {cout << str << endl;}   //вывод всех элементов вектора на консоль
void saveInFile(string pathToCatalog, string fileName); //сохранение в файл

vector<char*> endStr;

int main()
{

    string pathToFile="C:\\test.txt";
    //получаем имя файла
    string nameFile=pathToFile.substr(pathToFile.rfind('\\')+1,pathToFile.rfind('.')-(pathToFile.rfind('\\')+1));

    readFromFile(pathToFile);

    sort(endStr.begin(), endStr.end(), comparisionFunc);
    for_each(endStr.begin(), endStr.end(), showAllStr);

    saveInFile("C:\\", test1);

    return 0;
}
vector<char*> readFromFile(string pathToFile)
{
    vector<string> arrayStr;
    ifstream fileIn;
    fileIn.open(pathToFile);
    if (fileIn.is_open())
    {
        istream_iterator<string> iterBegin(fileIn), iterEnd;
        copy(iterBegin, iterEnd, back_inserter(arrayStr));
        for_each(arrayStr.begin(), arrayStr.end(), insertInVectorChar);

        fileIn.close();
    }
    else
    {
        cout << "Can't open file "+pathToFile;
    }
    return endStr;
}

void insertInVectorChar(string str)
{
    char *cstr = new char[str.size() + 1];
    strcpy(cstr, str.c_str());
    cstr[str.size()]='\0';
    endStr.push_back(cstr);
}

bool comparisionFunc(const char *str1, const char *str2)
{
    return strcmp(str1, str2) < 0;
}

void saveInFile(string pathToCatalog, string fileName)
{
    ofstream fileOut;
    fileOut.open((pathToCatalog+fileName+".str").c_str(),ios_base::out|ios_base::trunc);
    if(fileOut.is_open())
    {
        ostream_iterator<char*> iterBegin(fileOut, "\n");
        copy(endStr.begin(),endStr.end(),iterBegin);
        fileOut.close();
        cout<<"Файл "+fileName+".str"+" сохранен в "+pathToCatalog<<endl;
    }
    else
    {
        cout<<"Can't open file "+pathToCatalog+fileName+".str";
    }
}
