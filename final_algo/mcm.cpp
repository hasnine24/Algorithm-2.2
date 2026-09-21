#include<bits/stdc++.h>
using namespace std;

void printOptimalParenthesis(int s[][100], int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        cout << ")";
    }
}


void matrixChainOrder(int p[], int n)
{
    int m[100][100];
    int s[100][100];

    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k]+ m[k + 1][j]+ p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum Cost = "<< m[1][n] << endl;
    cout << "Optimal Parenthesization = ";
    printOptimalParenthesis(s, 1, n);
    cout << endl;
}


int main()
{
    int p[] = {10, 20, 30, 40, 30};
    int n = sizeof(p) / sizeof(p[0]) - 1;
    matrixChainOrder(p, n);
    return 0;
}