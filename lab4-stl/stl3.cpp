#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#define CLR while(fgetc(input) == '\n')

using namespace std;

void sortByName(vector<char*> stringVector)
{
    char temp[81];
    bool exit = false;

    while (!exit)
    {
        exit = true;
        for (vector<char*>::iterator i = stringVector.begin(); i != stringVector.end() - 1; i++)
            if (strcmp(*i, *(i+1)) > 0)
            {
                strcpy(temp, *i);
                strcpy(*i, *(i+1));
                strcpy(*(i+1), temp);
                exit = false;
            }
    }
}

int main()
{
    FILE *input, *output;
    char filename[81]; //Вводить без .txt
    vector<char*> stringVector;

    char bufname[81];

    do
    {
        cout << "Enter input-file name (without '.txt'):" << endl;
        cin >> filename;
        strcpy(bufname, filename);
        input = fopen(strcat(filename, ".txt"), "r");
    }
    while(input == NULL);

    int count = 0;
    while(!feof(input))
    {
        char buf[81];
        fgets(buf, 81, input);
        count++;
    }
    fclose(input);

    stringVector.reserve(count);
    input = fopen(filename, "r");

    char* buf;
    while(!feof(input))
    {
        buf = new char[81];
        fgets(buf, 81, input);
        stringVector.push_back(buf);
    }
    fclose(input);

    sortByName(stringVector);

    output = fopen(strcat(bufname, ".srt"), "w");

    for(vector<char*>::iterator i = stringVector.begin(); i != stringVector.end(); i++)
    {
        fprintf(output, "%s", *i);
        cout << *i;
    }

    fclose(output);

    return 0;
}
