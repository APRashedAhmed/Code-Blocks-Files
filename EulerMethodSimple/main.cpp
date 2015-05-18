#include <iostream>
#include <iomanip>

using namespace std;

int const n = 11;

double ft(double a, double b, double c, double t, double y)
{
    return a + b*y + c*t;
}

int main()
{
    double a, b, c, t, h;
    double y[n];

    a = 4;
    b = 2;
    c = -1;
    h = 0.1;

    y[0] = 1.0;
    t = 0.0;

    for(int i=0; i<n; i++)
    {
        cout << setw(5) << t << setw(10) << y[i] << endl;

        y[i+1] = y[i] + ft(a, b, c, t, y[i]) * h;
        t = h*(i+1);
    }

}
