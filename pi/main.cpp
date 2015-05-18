#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
    double sum = 0;
    srand48(time(NULL));

    const int n = 10000;

    for (int i = 0; i < n; i++)
    {
        double x = drand48();
        double y = drand48();

        if ((x*x + y*y) < 1.0)
            sum++;
    }

    double pi = 4.0*sum/n;

    cout << "pi = " << pi << endl;
    return 0;
}
