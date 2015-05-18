#include <iostream>

using namespace std;

const int n = 32;

double rho(int i, int j)
{
    if ((i == n/2) && (j == n/4))
    {
        return +1;
    }
    else if ((i == n/2) && (j == n*3/4))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    const int iter_count = 1000;

    double psi[n][n];
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            psi[x][y] = 0;
        }
    }

    int i = 0;
    while (i < iter_count)
    {
        for (int x = 1; x < n-1; x++)
        {
            for (int y = 1; y < n-1; y++)
            {
                psi[x][y] = -0.5*rho(x,y) + 0.25 * (psi[x+1][y] + psi[x-1][y] + psi[x][y+1] + psi[x][y-1]);
            }
        }
        i++;
    }

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            cout << x << " " << y << " " << psi[x][y] << endl;
        }
    }

    return 0;
}
