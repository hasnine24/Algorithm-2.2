#include <bits/stdc++.h>
using namespace std;

char board[20][20];
int n;

bool isSafe(int row, int col)
{
    for (int i = col; i >= 0; i--)
    {
        if (board[row][i] == 'Q')
            return false;
    }

    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void nqueen(int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return ;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 'Q';
            nqueen(row + 1);
            board[row][col] = '.';
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '.';
        }
    }
    nqueen(0);
    return 0;
}