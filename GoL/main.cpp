//This is a Conway's Game of Life Simulation that supports any array of size MxN
//and also allows for an inputted time step between iterations. Initial states are
//inputted manually or using a random filling function where one can input the
//percent of filling. The program is setup right now for a 23x39 array, 15% filling
//chance for the initial state, running 50 iterations, with a 500 millisecond time
//step between each one. As if right now the boundary conditions are setup to be
//permanently dead cells when applying the GoL rules. The rules for GoL are as
//follows: 1) Any live cells with fewer than 2 neighbors dies, as if caused by
//under-population. 2) Any live cell with two or three neighbors lives on to the
//next generation. 3) Any live cell with more than three live neighbors dies,
//as if by overcrowding. 4) Any dead cell with exactly three live neighbors
//becomes a live cell, as if by reproduction.

#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int LSize = 23;   //length of the simulation array
const int WSize = 39;   //width of the simulation array

const int L = LSize + 2;    //length of total array including boundaries
const int W = WSize + 2;    //Width of the total array including boundaries

void TimeStep(int step);
void ClearBoard(bool Brd[L][W]);
void RandomFill(bool Brd[L][W], int percent);
void CopyBoard(bool A[L][W], bool B[L][W]);
void PrintBoard(bool Brd[L][W]);
int NCount(bool Brd[L][W], int m, int n);
bool ApplyRules(int NCount, bool M);
void IterateBoard(bool Brdt0[L][W], bool Brdt1[L][W]);
void RunGoL(bool Brd1[L][W], int iterations, int timestep);
void PBC(bool A[L][W]);

int main()
{
    int iterations = 50;    //Defines how many times the simulation will run
    int TimeStep = 350;     //Defines how long of a timestep in milliseconds there should be between
                            //iterations(to allow for viewing)
    bool Brd1[L][W];

    ClearBoard(Brd1);
/*
    Brd1[1][1] = 1;
    Brd1[1][2] = 1;
    PrintBoard(Brd1);

    PBC(Brd1);

    PrintBoard(Brd1);
*/
    RandomFill(Brd1, 15);   //Creates an initial state for the board with a % chance of it being alive
                            //according to the second int
    RunGoL(Brd1, iterations, TimeStep);
}

void TimeStep(int step) //Inserts a time step in ms
{
    clock_t t = clock();

    while(clock() - t <= step) {}
}

void ClearBoard(bool Brd[L][W]) //Sets the board to all dead including boundaries
{
    for(int i = 0; i <= L-1; i++)
        for(int j = 0; j <= W-1; j++)
            Brd[i][j] = 0;
}

void RandomFill(bool Brd[L][W], int percent)    //Goes through each cell and has an inputted percent
{                                               //chance of filling it
    srand (time(NULL));
    ClearBoard(Brd);

    for(int i = 1; i <= LSize; i++)
        for(int j = 1; j <= WSize; j++)
        {
            int r = rand() % 100 + 1;

            if(r <= percent)
                Brd[i][j] = 1;
            else
                Brd[i][j] = 0;
        }
}

void CopyBoard(bool A[L][W], bool B[L][W])  //Copies Board A into board B
{
    for(int i = 1; i < L-1; i++)
        for(int j = 1; j < W-1; j++)
            B[i][j] = A[i][j];
}

void PrintBoard(bool Brd[L][W]) //Prints the board to the console
{
    for(int i = 1; i <= LSize; i++)
    {
        for(int j = 1; j <= WSize; j++)
        {
            cout << " ";

            if(Brd[i][j] == 0)
                cout << ".";
            else if(Brd[i][j] == 1)
                cout << "O";
        }
        cout << endl;
    }
    cout << endl;
}

int NCount(bool Brd[L][W], int m, int n)    //Determines the count around a cell
{
    int Count = 0;

    for(int i = m-1; i <= m+1; i++)
        for(int j = n-1; j <= n+1; j++)
            if(i != m || j != n)
                if(Brd[i][j] == 1)
                    Count++;

    return Count;
}

void PBC(bool A[L][W])
{
    for(int i = 0; i <= L-1; i++)
    {
        A[0][i] = A[L-2][i];
        A[L-1][i] = A[1][i];
    }

    for(int i = 0; i <= L-1; i++)
    {
        A[i][0] = A[i][W-2];
        A[i][W-1] = A[i][1];
    }
}

bool ApplyRules(int NCount, bool M) //Returns a 0 or 1 for a selected cell using the GoL rules
{
    if(NCount < 2 || NCount > 3)
        return 0;

    else if(NCount == 3)
        return 1;

    else if(NCount == 2)
        return M;
}
void IterateBoard(bool Brdt0[L][W], bool Brdt1[L][W])   //Creates another array containing the state
{                                                       //of the next time step
    for(int i = 1; i <= LSize; i++)
        for(int j = 1; j <= WSize; j++)
            Brdt1[i][j] = ApplyRules(NCount(Brdt0, i, j), Brdt0[i][j]);
}

void RunGoL(bool Brd1[L][W], int iterations, int timestep)  //Runs the GoL with a defined time step and
{                                                           //set number of iterations
    bool Brd2[L][W];
    ClearBoard(Brd2);
    PBC(Brd1);
    PrintBoard(Brd1);

    for(int i = 0; i < iterations; i++)
    {
        TimeStep(timestep);
        IterateBoard(Brd1, Brd2);
        PBC(Brd2);
        PrintBoard(Brd2);
        CopyBoard(Brd2, Brd1);
    }
}
