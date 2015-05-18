#include <iostream>
#include <iomanip>
#include <stddef.h>

using namespace std;

const int N = 10;

void FirstLastName(string *p_firstn, string *p_lastn)
{
    cout << "Please enter your first name :\n";

        cin >> *p_firstn;

    cout << "\nNow your last name please:\n";

        cin >> *p_lastn;
}

void PrintFirstLastName(string *p_firstn, string *p_lastn)
{
    cout << "Your name is " << *p_firstn << " " << *p_lastn << endl;
}

void PrintIndexes(string *p1, string *p2, string *p3, string *p4)
{
    cout << p1 << endl << p2 << endl << p3 << endl << p4;
}


void InitTable(int **PP)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            PP[i][j] = (i+1) * (j+1);
}


int main()
{
    //Pointers & arrays

    int **PP = NULL;

    PP = new int*[N];

    for(int i = 0; i < N; i++)
        PP[i] = new int[N];


    InitTable(PP);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout <<  setw(5) << PP[i][j];

        cout << endl;
    }

    //for(int i = 0; i < N; i++)
      //  cout << p[i] << endl;

    /*string firstname;
    string lastname;
    string firstname2;
    string lastname2;

    string *P_firstname = &firstname;
    string *P_lastname = &lastname;
    string *P_firstname2 = &firstname2;
    string *P_lastname2 = &lastname2;

    PrintIndexes(P_firstname, P_lastname, P_firstname2, P_lastname2);*/

    //FirstLastName(&firstname, &lastname);
    //PrintFirstLastName(&firstname, &lastname);
}
