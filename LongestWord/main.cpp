#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int ListSize()
{
    string line;
    ifstream words("list.txt");
    int n = 0;

    while(getline(words,line))
        n++;

    return n-1;
}

const int n = ListSize();

void QSByLen(string A[], int left, int right, int pivot);
void PrintElem(string A[]);
void MakeAr(string A[]);

int main()
{
    string A[n];
    MakeAr(A);

    QSByLen(A, 0, n, 0);
    PrintElem(A);
}

/*string LongestWordComb(string A[])
{
    for int i = n; i != 0; i--
}*/

void QSByLen(string A[], int left, int right, int pivot)
{
    int l = left;
    int r = right;

    while(l <= r)
    {
        while(A[l].length() < A[pivot].length())
            l++;

        while(A[r].length() > A[pivot].length())
            r--;

        if(l <= r)
        {
            swap(A[l],A[r]);
            l++;
            r--;

            if(A[l].length() == A[r].length())
                r--;
        }
    }

    if(left < r)
        QSByLen(A, left, r, pivot + 1);

    if(l < right)
        QSByLen(A, l, right, pivot + 1);
}

void MakeAr(string A[])
{
    string line;
    ifstream words("list.txt");

    for(int i = 0; i<=n; i++)
    {
        getline(words,line);
        A[i] = line;
    }
}

void PrintElem(string A[])
{
    for(int i = 0; i <= n; i++)
        cout << A[i] << endl;
}

