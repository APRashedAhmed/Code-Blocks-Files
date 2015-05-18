#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int const n=3;

void SetMat(double A[n][n])
{
    if(n==3)
    {
        A[0][0] = 2;
        A[0][1] = 4;
        A[0][2] = -2;
        A[1][0] = 4;
        A[1][1] = 9;
        A[1][2] = -3;
        A[2][0] = -2;
        A[2][1] = -3;
        A[2][2] = 7;
    }
    else
    {
        A[0][0] = 4;
        A[0][1] = 4;
        A[1][0] = 3;
        A[1][1] = 12;
    }
}

void SetMat(double A[n])
{
    if(n==3)
    {
        A[0] = 2;
        A[1] = 8;
        A[2] = 10;
    }
    else
    {
    A[0] = 24;
    A[1] = 24;
    }
}

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

void InitMat(double A[n])
{
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
            A[i] = 1;
        else
            A[i] = 0;
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

void InputMat(double A[n])
{
    cout << "Enter values of matrix: \n\n";

    for(int i=0; i<n; i++)
    {
        cout << "   Row " << i << ": ";
        cin >> A[i];
    }
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

void PrintMat(double A[n])
{
    cout << endl;

    for(int i=0; i<n; i++)
        cout << "  | " << A[i] <<  " |" << endl;

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

void MultMat(double A[n][n], double B[n], double AB[n])
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            AB[i] = AB[i] + A[i][j]*B[j];
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

void PrintLinSys (double A[n][n], double b[n])
{
    cout << endl;

    string x[n];

    for(int i=0; i<n; i++)
        x[i] = "x";

    for(int i=0; i<n; i++)
    {
        cout << "  | ";
        for(int j=0; j<n; j++)
        {
            cout << A[i][j];

            if(j!=n-1)
                cout << "  ";
        }
        cout  << " || " << x[i] << i << " | = | " << b[i] << " |" << endl;
    }
    cout << endl;
}

void SolvLinSys(double A0[n][n], double b0[n], double b[n])
{
    double D[n][n];
    double P[n];

//Dummy Matrix
    for(int i=0; i<n; i++)
    {
        P[i] = b0[i];

        for(int j=0; j<n; j++)
            D[i][j] = A0[i][j];
    }

 //   PrintMat(D);
 //   PrintMat(P);

    for(int i=0; i<n; i++)
    {
        double d = D[i][i];
        for(int a=i+1; a<n; a++)
        {
            double m = D[a][i];

            for(int b=i; b<n; b++)
            {
                double o = D[i][b];

                D[a][b] = D[a][b] - o*(m/d);
            }

                P[a] = P[a] - P[i]*(m/d);
        }

 //       PrintMat(D);
 //       PrintMat(P);
    }

    for(int i=n-1; i>0; i--)
    {
        double d = D[i][i];
        for(int a=i-1; a>=0; a--)
        {
            double m = D[a][i];

            for(int b=i; b>0; b--)
            {
                double o = D[i][b];

                D[a][b] = D[a][b] - o*(m/d);
            }

                P[a] = P[a] - P[i]*(m/d);
        }

//        PrintMat(D);
//        PrintMat(P);
    }

    for(int i=0; i<n; i++)
    {
        b[i] = P[i]/D[i][i];
    }
//        PrintMat(D);
//        PrintMat(P);
}

void EchLinSys(double A0[n][n], double b0[n],double A[n][n], double b[n])
{
    double D[n][n];
    double P[n];

//Dummy Matrix
    for(int i=0; i<n; i++)
    {
        P[i] = b0[i];

        for(int j=0; j<n; j++)
            D[i][j] = A0[i][j];
    }

 //   PrintMat(D);
 //   PrintMat(P);

    for(int i=0; i<n; i++)
    {
        double d = D[i][i];
        for(int a=i+1; a<n; a++)
        {
            double m = D[a][i];

            for(int b=i; b<n; b++)
            {
                double o = D[i][b];

                D[a][b] = D[a][b] - o*(m/d);
            }

                P[a] = P[a] - P[i]*(m/d);
        }

 //       PrintMat(D);
 //       PrintMat(P);
    }

    for(int i=n-1; i>0; i--)
    {
        double d = D[i][i];
        for(int a=i-1; a>=0; a--)
        {
            double m = D[a][i];

            for(int b=i; b>0; b--)
            {
                double o = D[i][b];

                D[a][b] = D[a][b] - o*(m/d);
            }

                P[a] = P[a] - P[i]*(m/d);
        }

//        PrintMat(D);
//        PrintMat(P);
    }

    for(int i=0; i<n; i++)
    {
        b[i] = P[i];

        for (int j=0; j<n; j++)
            A[i][j] = D[i][j];
    }
}

void PrintSolLinSys(double b[n])
{
    double A[n][n];
    cout << endl;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(i==j)
                A[i][j] = 1;
            else
                A[i][j] = 0;
        }

    PrintLinSys(A, b);
}

int main()
{
    double A[n][n];
    double b[n];
    double b0[n];

//    InitMat(A);
//    InitMat(b);

//    InputMat(A);
//    InputMat(b);

    SetMat(A);
    SetMat(b);

    MultMat(A, b, b0);

    PrintMat(A);
    PrintMat(b);
    PrintMat(b0);

//    PrintSolLinSys(b);

    PrintLinSys(A, b);

//    SolvLinSys(A, b, b0);
    SolvLinSys(A, b, b0);

    PrintSolLinSys(b0);
}
