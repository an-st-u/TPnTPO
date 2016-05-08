#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

int main()
{
    FILE *input;
    char filename[81];
    list<int> *numbers = new list<int>();

    do
    {
        cout << "Enter input-file name:" << endl;
        cin >> filename;
        input = fopen(filename, "r");
    }
    while(input == NULL);

    while(!feof(input))
    {
        int buf;
        fscanf(input, "%d", &buf);
        numbers->push_back(buf);
    }

    fclose(input);

    list<int> *uniqueNumbers = new list<int>();
    list<int> *frequencies = new list<int>();

    for(list<int>::iterator n = numbers->begin(); n != numbers->end(); n++)
    {
        bool exists = false;
        for(list<int>::iterator un = uniqueNumbers->begin(); un != uniqueNumbers->end() && !exists; un++)
            if(*n == *un)
                exists = true;
        if(!exists)
            uniqueNumbers->push_back(*n);
    }

    for(list<int>::iterator un = uniqueNumbers->begin(); un != uniqueNumbers->end(); un++)
    {
        frequencies->push_back(0);
        for(list<int>::iterator n = numbers->begin(); n != numbers->end(); n++)
            if(*un == *n)
                frequencies->back()++;
        cout << *un << " " << frequencies->back() << endl;
    }

    return 0;
}
