#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double g(double r, double x)
{
    return r * sin(M_PI*x);
}

int main()
{
    double x=1;
    double r=0.85;

    int N = 1000;

    for(int n = 0; n < N; n++)
    {
        if (n == 0)
            cout << setw(30) << x << setw(30) << 0 << endl;

        else if (n%2 == 1)
        {
            cout << setw(30) << x << setw(30) << g(r, x) << endl;
            x = g(r, x);
        }

        else
            cout << setw(30) << x << setw(30) << x << endl;
    }
}

// For period-1, r = 0.65
// For period-2, r = 0.80
// For period-4, r = 0.85
