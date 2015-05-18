#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int n = 100;

const int PART = 1; // determines what to print values for (either part 1, 2, 3, or 4)

void ReadCities(int x[n], int y[n])
{
    ifstream read("cities.dat");
    int j, nextX, nextY;
    for (int i=0; i<n; i++)
    {
        read >> j >> nextX >> nextY;
        x[i] = nextX;
        y[i] = nextY;
    }
}

// if i is outside of bounds of array, then it wraps around
int VectorGetElement(int a[n], int i)
{
    i %= n;
    if (i < 0)
        i += n;
    return a[i];
}

double EnergyConfig(int x[n], int y[n], int A[n])
{
    double sum = 0;
    for (int i=0; i<n; i++)
    {
        int next_city = VectorGetElement(A, i+1);
        double diffX = VectorGetElement(x, next_city) - VectorGetElement(x, A[i]);
        double diffY = VectorGetElement(y, next_city) - VectorGetElement(y, A[i]);
        sum += sqrt(diffX*diffX + diffY*diffY);
    }
    return sum;
}

void PrintPath(int A[n])
{
    cout << "[";
    for (int i=0; i<n-1; i++) {
        cout << A[i] << ", ";
    }
    cout << A[n-1] << "]\n";
}

// this swaps values at indices a and b in an array R
void Swap(int A[n], int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

double ConfigPropRatio(double E_current, double E_proposed, double kT)
{
    return exp((-E_proposed + E_current)/kT);
}

int main()
{
    srand48(time(NULL));

    int city_x[n], city_y[n];
    ReadCities(city_x, city_y);

    int R[n];
    // initial configuration is 0,1,2,3,...N-1
    for (int i=0; i<n; i++)
    {
        R[i] = i;
    }

    double current_energy = EnergyConfig(city_x, city_y, R);

    // Part 1: print length of initial route
    if (PART == 1)
    {
        cout << current_energy << endl;
    }

    // metropolis importance sampling
    int num_iter = 100 * n;

    double kT = 100;

    while (kT >= 1)
    {
        int i = 0;
        while (i < num_iter)
        {
            // randomly select a pair of cities
            int r1 = (int)(drand48() * ((double)n));

            // make sure that r1 and r2 arent the same city
            int r2 = (int)(drand48() * ((double)n));
            while (r2 == r1)
            {
                r2 = (int)(drand48() * ((double)n));
            }

            // swap the cities
            Swap(R, r1, r2);

            double proposed_energy = EnergyConfig(city_x, city_y, R);

            double prob_ratio = ConfigPropRatio(current_energy, proposed_energy, kT);

            if (prob_ratio > 1)
            {
                // accept this configuration
                current_energy = proposed_energy;
            }
            else
            {
                double omega = drand48();
                if (omega < prob_ratio)
                {
                    // accept this configuration
                    current_energy = proposed_energy;
                } else
                {
                    // swap
                    Swap(R, r1, r2);
                }
            }

            i++;
        }

        // Part 3: at each temp, print last route-length energy divided by num of cities
        if (PART == 3)
        {
            cout << kT << "  " << current_energy/n << endl;
        }

        kT -= 1;
    }

    // part 2: print length of final route
    if (PART == 2)
    {
        cout << current_energy << endl;
    }

    // Part 4: print final coords
    if (PART == 4)
    {
        for (int i=0; i<n; i++) {
            int city = R[i];
            cout << city_x[city] << "  " << city_y[city] << endl;
        }
    }

    return 0;
}


