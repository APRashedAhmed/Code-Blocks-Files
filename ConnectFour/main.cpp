//Connect Four Game

#include <iostream>
#include <stddef.h>
#include <iomanip>

using namespace std;

void InitBoard(int **PP, int gamesize)
{
    for(int i = 0; i < gamesize; i++)
        for(int j = 0; j < gamesize; j++)
            PP[i][j] = 0;
}

void PrintBoard(int **PP, int gamesize)
{
    for(int i = 0; i < gamesize; i++)
    {
        for(int j = 0; j < gamesize; j++)
        {
            if(PP[i][j] == 1)
                cout << "+  ";
            else if(PP[i][j] == 2)
                cout << "o  ";
            else
                cout << "-  ";
        }
        cout << endl;
    }
    cout << endl;
}

void Player1DropPiece(int **PP, int gamesize, int column)
{
    int i = 1;
    while(PP[gamesize - i][column] != 0)
        i++;

    PP[gamesize - i][column]++;
}

void Player2DropPiece(int **PP, int gamesize, int column)
{
    int i = 1;
    while(PP[gamesize - i][column] != 0)
        i++;

    PP[gamesize - i][column]++;
    PP[gamesize - i][column]++;
}

int main()
{
    int gamesize = 5;
    //cout << "Please enter the size of the connect four game: \n";
    //cin >> gamesize;

    int **PP = new int*[gamesize];
    for(int i = 0; i < gamesize; i++)
        PP[i] = new int[gamesize];

    InitBoard(PP, gamesize);
    PrintBoard(PP, gamesize);

    Player1DropPiece(PP, gamesize, 3);

    Player2DropPiece(PP, gamesize, 3);

    Player1DropPiece(PP, gamesize, 3);
    Player1DropPiece(PP, gamesize, 3);

    PrintBoard(PP, gamesize);
}
