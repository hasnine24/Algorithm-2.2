#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;

    int weight[100], value[100];
    int V[100][100];

    // Input
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    // Initialize first row
    for (int w = 0; w <= W; w++)
    {
        V[0][w] = 0;
    }

    // Initialize first column
    for (int i = 0; i <= n; i++)
    {
        V[i][0] = 0;
    }

    // 0/1 Knapsack DP
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weight[i] <= w)
            {
                if (value[i] + V[i - 1][w - weight[i]] > V[i - 1][w])
                {
                    V[i][w] = value[i] + V[i - 1][w - weight[i]];
                }
                else
                {
                    V[i][w] = V[i - 1][w];
                }
            }
            else
            {
                V[i][w] = V[i - 1][w];
            }
        }
    }

    // Maximum value
    cout << "Maximum Value = " << V[n][W] << endl;

    // Finding selected items
    int i = n;
    int k = W;

    cout << "Selected Items: ";

    while (i > 0)
    {
        if (V[i][k] != V[i - 1][k])
        {
            cout << i << " ";

            k = k - weight[i];
        }

        i = i - 1;
    }

    cout << endl;

    return 0;
}