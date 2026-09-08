#include<bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];
int dp[1005][1005];

int knapsack(int i, int mx_weight)
{
    if(i < 0 || mx_weight <= 0)
        return 0;

    if(dp[i][mx_weight] != -1)
        return dp[i][mx_weight];

    if(weight[i] <= mx_weight)
    {
        int op1 = knapsack(i-1, mx_weight-weight[i]) + val[i];
        int op2 = knapsack(i-1, mx_weight);

        dp[i][mx_weight] = max(op1, op2);
        return dp[i][mx_weight];
    }
    else
    {
        dp[i][mx_weight] = knapsack(i-1, mx_weight);
        return dp[i][mx_weight];
    }
}

void printAns(int i, int mx_weight)
{
    if(i < 0 || mx_weight <= 0)
        return;

    if(weight[i] > mx_weight)
    {
        printAns(i-1, mx_weight);
    }
    else
    {
        int take = knapsack(i-1, mx_weight-weight[i]) + val[i];
        int notTake = knapsack(i-1, mx_weight);

        if(take > notTake)
        {
            cout << "Item " << i+1 << endl;
            printAns(i-1, mx_weight-weight[i]);
        }
        else
        {
            printAns(i-1, mx_weight);
        }
    }
}

int main()
{
    int n, mx_weight;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> val[i];

    for(int i = 0; i < n; i++)
        cin >> weight[i];

    cin >> mx_weight;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= mx_weight; j++)
            dp[i][j] = -1;

    int ans = knapsack(n-1, mx_weight);

    cout << "Maximum Value = " << ans << endl;

    cout << "Selected Items:" << endl;
    printAns(n-1, mx_weight);

    return 0;
}