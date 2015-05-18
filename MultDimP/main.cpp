#include <iostream>

using namespace std;

const int N = 5;

int **InitGrid()
{
    int **PP;
    PP = new int*[N];

    for(int i = 0; i < N; i++)
        PP[i] = new int[N];
    return PP;
}

void SetIncr(int **PP)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            PP[i][j] = 1;
}

void PrintGrid(int **PP)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout << PP[i][j] << " ";

        cout << endl;
    }
}

void freeGrid(int **grid)
{
    for(int i = 0; i < N; i++)
        delete grid[i];

    return ;
}

int main()
{
    int **PP;

    PP = InitGrid();
    SetIncr(PP);
    PrintGrid(PP);
    freeGrid(PP);
    PrintGrid(PP);
        freeGrid(PP);


}
