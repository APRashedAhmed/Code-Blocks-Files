#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;

double gx(double x, double y, double a);
double gy(double x, double b);

ofstream fout_xy("x-y.dat");
ofstream fout_bif("bif.dat");

int main()
{

    double x0;
    double y0;

    double x1;
    double y1;

    double da=0.00001;
    double amin;

    x0 = 0.8;
    y0 = 0.5;

    double a = 1.4;
    double b = 0.3;

    for(int i =1; i<5000; i++)
    {
        x1 = gx(x0, y0, a);
        y1 = gy(x0, b);

        fout_xy << i << setw(16) << x1 << setw(16) << y1 << endl;

        x0=x1;
        y0=y1;
    }

    return 0;
}

double gx(double x, double y, double a)
{
    return 1-a*pow(x,2)+y;
}

double gy(double x, double b)
{
    return b-x;
}
