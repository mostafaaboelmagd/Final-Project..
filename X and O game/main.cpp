#include <iostream>
using namespace std;

char player = 'X';
char matrix[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

void printmatrix()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void play()
{
    char position;
    cout << "Choose Your Position Player (" << player << ") : ";
    cin >> position;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (position == matrix[i][j])
            {
                matrix[i][j] = player;
            }
        }
    }
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}

char whowin()
{
    int Nowincounter = 0;


    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
        {
            return matrix[i][0];
        }
    }


    for (int i = 0; i < 3; i++)
    {
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
        {
            return matrix[0][i];
        }
    }


    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
    {
        return matrix[0][0];
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
    {
        return matrix[0][2];
    }


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
            {
                return 'A';
            }
        }
    }

    return 'M';
}

int main()
{
    while (whowin() == 'A')
    {
        printmatrix();
        play();
    }

    printmatrix();

    if (whowin() == 'X') cout << "Player X is Winner" << endl;
    else if (whowin() == 'O') cout << "Player O is Winner" << endl;
    else if (whowin() == 'M') cout << "No Winner - It's a draw" << endl;

    return 0;
}
