#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

typedef complex<double> doublecomplex;

const int N = 4;
const double pi = 3.1415926536;

int main()
{
    doublecomplex fx[N], w, Fq[N];

    w = doublecomplex(cos(2.0*pi/N), sin(2.0*pi/N));

    fx[0] = fx[2] = 1;
    fx[1] = fx[3] = -1;

    for (int m = 0; m < N; m++)
    {
        for (int l = 0; l < N; l++)
        {
            Fq[m] += (pow(w, m*l) * fx[l]);
        }

        printf("%.02f\n", real(Fq[m]));
    }
    return 0;
}
