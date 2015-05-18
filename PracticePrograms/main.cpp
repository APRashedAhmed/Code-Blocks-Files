#include <iostream>
#include <iomanip>

using namespace std;

const double a=1.0;
const double b=4.0;
const double c=2.0;

double f(double x)
{
    return a*x*x+b*x+c;
}

double g2(double x)
{
    return -(a*x*x-c)/(2.0*a*x+b);
}

int main()
{
    string answer;

    while(answer != "end")
    {
    double x;

    cout << "x= \n";
    cin >> x;

    for(int n=0; n<20; n++)
    {
        cout << setw(5) << n << setw(15) << x << setw(25) << f(x) << endl;
        x=g2(x);
    }

    cout << "\nType 'end' to end the program, anything else to loop\n";
    cin >> answer;
    }
}
