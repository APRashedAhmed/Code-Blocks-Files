#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double a;

double f(double x)
{
    return tanh(a*x) - x;
}

double g (double x)
{
    return x - (tanh(a*x) - x) / ((a/(cosh(a*x) * cosh(a*x))) - 1);
}

int main()
{
    double x;
    int N = 100;
    string ans = "y";

    a = 0.8;
    cout << "a = " << a << endl;

    while(ans == "y")
    {
        cout << "x0 = ";
        cin >> x;

        for (int i = 0; i < N; i++)
                x = g(x);

        cout << "solution: " << x << endl << endl;
        cout << "Rerun? Type y for rerun:";
        cin >> ans;
    }

    ans = "y";

    a = 1.2;
    cout << "a = " << a << endl;

    while(ans == "y")
    {
        cout << "x0 = ";
        cin >> x;

        for (int i = 0; i < N; i++)
                x = g(x);

        cout << "solution: " << x << endl << endl;
        cout << "Rerun? Type y for rerun:";
        cin >> ans;
    }
}

//For a = = 0.8, root is 0.
//For a = 1.2, roots are -0.65857, 0 and 0.65857
