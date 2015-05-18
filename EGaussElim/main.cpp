#include <iostream>
#include <iomanip>

using namespace std;

const int n = 3;

// prints out a matrix
void MatrixPrint(double a[n][n])
{
	for (int r = 0; r < n; r++)
    {
		for (int c = 0; c < n; c++)
        {
			cout << setw(3) << a[r][c] << " ";
		}
		cout << endl;
	}
}

// prints out a vector
void VectorPrint(double a[n])
{
    for (int r = 0; r < n; r++)
    {
		cout << setw(3) << a[r] << endl;
	}
}

// row reduces matrix to triangular form
void MatrixRowReduce(double A[n][n], double b[n]) {
    for (int k = 0; k <= n; k++)
    {
        if (A[k][k] == 0)
        {
            cout << "error: cannot row reduce matrix because it has a diagonal zero element." << endl;
            return;
        }

        for (int i = k+1; i < n; i++)
        {
            double m = A[i][k] / A[k][k];
            b[i] -= m * b[k];

            for (int j = 0; j < n; j++)
            {
                A[i][j] -= m * A[k][j];
            }
        }
    }
}

// performs back-substitution (and solves for x)
void MatrixBackSubstitute(double A[n][n], double b[n], double x[n])
{
    if (A[n-1][n-1] == 0)
    {
        cout << "error: this linear system cannot be solved." << endl;
    }

    x[n-1] = b[n-1] / A[n-1][n-1];

    for (int k=n-2; k >= 0; k--)
    {
        x[k] = b[k];

        for (int j=k+1; j<n; j++)
        {
            x[k] -= A[k][j] * x[j];
        }

        x[k] /= A[k][k];
    }
}

int main()
{
    // this program uses gaussian elimination and back substitution to solve A*x = b

    double A[n][n] = {{ 2,  4, -2},
                      { 4,  9, -3},
                      {-2, -3,  7}};

    double b[n] = {2, 8, 10};

    cout << "before gaussian elimination: " << endl;

    MatrixPrint(A);
    VectorPrint(b);

    MatrixRowReduce(A, b);

    cout << "after gaussian elimination: " << endl;

    MatrixPrint(A);
    VectorPrint(b);

    double x[n];

    MatrixBackSubstitute(A, b, x);

    cout << "after back substitution: " << endl;
    VectorPrint(x);

    return 0;
}







