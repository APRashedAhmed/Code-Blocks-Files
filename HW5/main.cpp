#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>

using namespace std;

double drand48()
{
    return ((double)rand())/RAND_MAX;
}

double f(double x)
{
    return (exp(x) - 1.0)/(exp(1.0) - 2.0);
}

double p(double x)
{
    return 2.0 * x;
}

double RandSamp()
{
    int N = 1000;
    double sum = 0;

    for(int i = 0; i < N; i++)
    {
        double x = drand48();
        sum += f(x);
    }

    double ans = sum / N;
    return ans;
}

double ImpSamp()
{
    int N = 1000;
    double sum = 0;

    for(int i = 0; i < N; i++)
    {
        double y = drand48();

        //y can sometimes be too small ~0
        while(y < 0.0000001)
            y = drand48();

        sum += (f(sqrt(y)) / p(sqrt(y)));
    }
    double ans = sum / N;
    return ans;
}

double MetroMeth()
{
    int N = 1000;
    double sum = 0;

    double x_m = 1;
    double x_t = drand48();

    for(int i = 0; i < N; i++)
    {
        sum += f(x_m)/p(x_m);

        x_t = drand48();

        if (x_t >= x_m)
            x_m = x_t;

        else
        {
            double r = drand48();
            if (r < x_t/x_m)
                x_m = x_t;
        }
    }

    double ans = sum / N;
    return ans;
}

//This points var to function A
//Syntax is to put the same type of function that you will input (in this case, a double) followed
//by a *A in parentheses, and then the input types in another set after it. Then when you call it
//in main, you just use the name of the function you are pointing to.
double var(double (*A)())
{
    int N = 100;

    double B[N];
    double ave = 0;
    double var = 0;

    for(int i = 0; i < N; i++)
    {
        ave += A();
        B[i] = A();
    }

    ave = ave/N;

    for(int i = 0; i < N; i++)
        var += (B[i]-ave)*(B[i]-ave);

    var = var/N;
    return var;
}

double sig(double (*A)())
{
    return sqrt(var(A));
}

//Smaller is better
double Acc(double (*A)())
{
    int N = 100;
    double ave = 0;

    for(int i = 0; i<N; i++)
        ave += abs(1-A());

    return ave/N;
}

int main()
{
    srand(time(NULL));

    double RS = RandSamp();
    double IS = ImpSamp();
    double MM = MetroMeth();

    cout << RS << setw(15) << 1-RS << setw(15) << Acc(RandSamp) << endl;
    cout << IS << setw(15) << 1-IS << setw(15) << Acc(ImpSamp) << endl;
    cout << MM << setw(15) << 1-MM << setw(15) << Acc(MetroMeth) << endl << endl;

//Notice the lack of () in the Randsamp used below.

    cout << var(RandSamp) << endl;
    cout << sig(RandSamp) << "\n\n";

    cout << var(ImpSamp) << endl;
    cout << sig(ImpSamp) << "\n\n";

//This NAN for some reason that I cannot figure out. Probably some quirk of the pointer.

    cout << var(MetroMeth) << endl;
    cout << sig(MetroMeth) << "\n\n";
}
