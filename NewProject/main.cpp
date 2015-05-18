#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int n = 12;

void MakeAr(string A[])
{
    ifstream words("sample.txt");
    if(words.is_open())
        for(int i = 0; i < n; ++i)
            words >> A[i];
}

void PrintElem(string A[])
{
    for(int i = 0; i < n; i++)
        cout << A[i] << endl;
}

int main()
{
    string A[n];
    MakeAr(A);
    PrintElem(A);
}
