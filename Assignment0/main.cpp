#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int const n=3;

void InitMat(double A[n][n])
{
    //Generates a matrix that has alternating 0s and 1s.
    //It recreates the same hard coding below
    //But is generalizable to nxn matrices

 /*   A[0][0] = 0;
    A[0][1] = 1;
    A[0][2] = 0;
    A[1][0] = 1;
    A[1][1] = 0;
    A[1][2] = 1;
    A[2][0] = 0;
    A[2][1] = 1;
    A[2][2] = 0; */

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if((i+j)%2==0)
                A[i][j] = 0;
            else
                A[i][j] = 1;
        }
}

void TransMat(double A[n][n], double B[n][n])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            B[i][j]=A[j][i];
        }
    }
}

void InputMat(double A[n][n])
{
    //Input the values of a matrix through the console
    //Generalizable to nxn matrices

    cout << "Enter values of matrix: \n\n";

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cout << "   Row " << i << ", Column " << j  << ": ";
            cin >> A[i][j];
        }

    cout << endl;
}

void PrintMat(double A[n][n])
{
    //Prints any nxn matrix

    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << "  | ";

        for(int j=0; j<n; j++)
        {
            cout << A[i][j];

            if(j!=n-1)
                cout << "  ";
        }
        cout  << " |" << endl;
    }
    cout << endl;
}

void MultMat(double A[n][n], double B[n][n], double AB[n][n])
{
    //Matrix multiplication
    //generalizable to nxn

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            AB[i][j] = 0;

            for(int k=0; k<n; k++)
                    AB[i][j]=AB[i][j]+A[i][k]*B[k][j];
        }
}

void AddMat(double A[n][n], double B[n][n], double C[n][n])
{
    //Matrix addition
    //generalizable to nxn

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            C[i][j]=A[i][j]+B[i][j];
        }
}

int main ()
{
    double A[n][n];
    double B[n][n];
    double C[n][n];
    double D[n][n];
    double E[n][n];
    cout << "Matrix J: \n";

    InitMat(A);
//    InputMat(A);
//    PrintMat(A);

    InitMat(B);
//    InputMat(B);
    PrintMat(B);

    cout << "Matrix J^2: \n";

    MultMat(A, B, C);
    PrintMat(C);

    cout << "Matrix J^3: \n";

    MultMat(A, C, D);
    PrintMat(D);

//    InputMat(D);
//
//    TransMat(D, E);
//    PrintMat(E);
}
