#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

ofstream fout("PartI.dat");
double g(double r, double x)
{
        return r * sin(M_PI * x);
}

int main()
{
  double x=1;
  double r=.65;

  int iter = 1000;

  for(int n=0; n<iter; n++)
  {
        if (n == 0)
    {
        cout << setw(30) << x << setw(30) << 0 << endl;
    }
    else
    {
        cout << setw(30) << x << setw(30) << g(r, x) << endl;
        x = g(r, x);
    }

  }
}

// for period-1, r = 0.6500
// for period-2, r = 0.8000
// for period-4, r = 0.8500
