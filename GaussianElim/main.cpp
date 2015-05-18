#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

using namespace std;

const int n=4;

double A[n+1][n+1];
double b[n+1];
double x[n+1];

double A0[n+1][n+1];
double b0[n+1];
double x0[n+1];

void printmat(double [n+1][n+1]);
void matmul (double [n+1][n+1]; double [n+1]; double[n+1]);

const double I0 = 1.1, d=1.6, a=5.0, g0=2.5, B=0.46, t=0.12, g=0.10;

int main()
{
    A[1][1]=1; A[1][2]=-1; A[1][3]=0; A[1][4]=-1;
    A[2][1]=B; A[2][2]=-1; A[2][3]=-B; A[2][4]=0;
    A[3][1]=t; A[3][2]= 0; A[3][3]=-1; A[3][4]=0;
    A[4][1]=g; A[4][2]=0; A[4][3]=0,;A[4][4]=-1;

    b[1]=I0; b[2]=-a; b[3]=-d; b[4]=-g0;

    for(int i=1; i<=n; i++)
    {
        b0[i]=b[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=2, j<=n, j++)
        {
            A0[i][j]=A[i][j];
        }
    }

    cout << "A=\n";
    printmat(A);

    //Gaussian Elimination

    double M=0;;

    for(int k=n-1; k>=1, k++)
    {
        x[k]=b[k];
        for(int j=k+1; j<=n; j++)
        {
            x[k]=x[k]-A[k][j]*x[j];
        }
        x[k]=x[k]/A[k][k];
    }

    cout << "x=" << "\n";
    for(int i=1; i<=n; i++)
    {
        cout << setw(8) << x[i] << endl;
    }

    //This is probably jumbled up!
    //Back Substitution
C:\Users\Abdullah\Documents\C++ Files\GaussianElim\main.cpp
    k[n]=b[n]/A[n][n]

    for(int k=1; k<=n-1; k++)
    {
        for(int i=k+1; i<=n i++)
        {
            M=A[i][k]/A[k][k];
            b[i]=b[i]-M*b[k];

            for(int j=1; j<=n; j++)
            {
                A[i][j]=A[i][j]-M*A[k][j];
            }
        }
    }

    return 0;

    matmul(A0,x,bb);
    cout << setw(16) << "A0*x" << setw(16) << "b" << setw(16) << "A0*x - b" << "\n";

    for(int i=1; i<=n, i++)
    {
        cout << setw() << "" << setw() << "" << setw() << "" << "\n";
        //Complete this
    }

}

void printmat(double mat[n+1][n+1])
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << setw(8) << mat[i][j];
        }
        cout << "\n";
    }

    cout << "\n";
}

//You need to write a matrix multiplication code so that the program
//above will work`
