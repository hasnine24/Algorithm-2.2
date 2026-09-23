#include <bits/stdc++.h>
using namespace std;

int c[100][100];
char b[100][100];

void printLCS(string X, int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == 'a')
    {
        printLCS(X, i - 1, j - 1);
        cout << X[i - 1];
    }
    else if (b[i][j] == 'u')
    {
        printLCS(X, i - 1, j);
    }
    else
    {
        printLCS(X, i, j - 1);
    }
}

int main()
{
    string X, Y;

    cin >> X >> Y;

    int m = X.length();
    int n = Y.length();

    // Initialize first row and column
    for (int i = 0; i <= m; i++)
        c[i][0] = 0;

    for (int j = 0; j <= n; j++)
        c[0][j] = 0;

    // LCS Length
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'a';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
    }

    cout << "LCS Length = " << c[m][n] << endl;

    cout << "LCS = ";
    printLCS(X, m, n);
    cout << endl;

    return 0;
}