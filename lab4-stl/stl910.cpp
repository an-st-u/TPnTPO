#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <conio.h>
#include <numeric>
#include <algorithm>

using namespace std;

/*--------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------*/
struct interval 
{
	float begin;
	float end;
};

int count(interval Interval, list<int> IntList)
{
	int counter = 0;
	for each (int currNumber in IntList)
	{
		if (currNumber >= Interval.begin && currNumber < Interval.end)
			counter++;
	}
	return counter;
}
/*--------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------*/

bool op(int elem1, int elem2)
{
	return elem1 > elem2;
}


int main()
{
	list<int> lines; // создаем список список
	ifstream in("C:/MyFiles/text_int.txt", ios::in); //ios::binary - бинарное открытие,ios::in - операции ввода
	ofstream out_file("C:/MyFiles/text_binary.dat", ios_base::binary);

	int d;
	while (true) {

		in >> d;
		if (in.fail()) { break; }
		out_file.write((char*)&d, sizeof(int));

	}

	in.close();
	out_file.close();

	in.open("C:/MyFiles/text_binary.dat", ios::in | ios_base::binary);
	while (true) 
	{
		in.read((char*)&d, sizeof(int));
		if (in.fail()) { break; }
		lines.push_back(d);
	}
	in.close();

	lines.sort(op); // сортируем контейнер
	// и записываем отсортированный контейнер в новый файл




	out_file.open("C:/MyFiles/text52.txt", ios::out); //открыть для записи
	ostream_iterator<int> file_out(out_file, " ");
	copy(lines.begin(), lines.end(), file_out);
	out_file.close();
	copy(lines.begin(), lines.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "quantity: " << lines.size() << endl;
	cout << "average: " << accumulate(lines.begin(), lines.end(), 0.0) / lines.size() << endl;
	int n = *max_element(lines.begin(), lines.end()) - *min_element(lines.begin(), lines.end());
	cout << "range: " << n << endl;



	/*--------------------------------------------------------------------------------------*/
	/*--------------------------------------------------------------------------------------*/
	list<interval> Intervals = list<interval>();
	int counter = 0;
	const int numberOfIntervals = 10;
	float IntervalLength = (*max_element(lines.begin(), lines.end()) - *min_element(lines.begin(), lines.end())) / (float)numberOfIntervals;
	if (IntervalLength > 0)
	{
		for (int i = 0; i < numberOfIntervals; i++)
		{
			interval currInterval;
			currInterval.begin = *min_element(lines.begin(), lines.end()) + IntervalLength*i;
			currInterval.end = currInterval.begin + IntervalLength;
			Intervals.push_back(currInterval);
		}
		counter = 0;
		cout << "Intervals: " << endl;
		for each (interval i in Intervals)
			cout << ++counter << ". (" << i.begin << "; " << i.end << ")" << endl;
		cout << endl;
		int MinIndex = 0;
		int MaxIndex = 0;
		int MinValue = count(Intervals.front(), lines);
		int MaxValue = count(Intervals.front(), lines);
		counter = 0;
		for each (interval currInterval in Intervals)
		{
			if (MinValue > count(currInterval, lines))
			{
				MinValue = count(currInterval, lines);
				MinIndex = counter;
				counter++;
			}
			if (MaxValue < count(currInterval, lines))
			{
				MaxValue = count(currInterval, lines);
				MaxIndex = counter;
				counter++;
			}
		}
		if (MinValue > count(Intervals.back(), lines) + 1)
		{
			MinValue = count(Intervals.back(), lines);
			MinIndex = numberOfIntervals - 1;
		}
		if (MaxValue < count(Intervals.back(), lines) + 1)
		{
			MaxValue = count(Intervals.back(), lines);
			MaxIndex = numberOfIntervals - 1;
		}
		cout << "Interval #" << MinIndex + 1 << " is the smallest" << endl <<
			"Interval #" << MaxIndex + 1 << " is the biggest" << endl;
	}
	else
	{
		cout << "There are no 10 intervals" << endl;
	}
	/*--------------------------------------------------------------------------------------*/
	/*--------------------------------------------------------------------------------------*/






	getch();
	return 0;
}
