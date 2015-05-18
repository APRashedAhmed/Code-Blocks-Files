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
  double x = 1;
  double r = 0.7;

  int iter = 1000;

  while( r<=1.0)
  {
    for(int n=0; n<iter; n++)
    {
       cout << setw(30) << r << setw(30) << x << endl;
        x = g(r, x);
    }
    r=r+0.0001;
  }
}
