#include<bits/stdc++.h>
using namespace std;

int val[1005];
int dp[1005][1005];
int ans[1005];

int subset_sum(int i, int sum)
{
    if(i < 0)
    {
        if(sum == 0) return 1;
        else return 0;
    }

    if(dp[i][sum] != -1)
        return dp[i][sum];

    if(val[i] <= sum)
    {
        int op1 = subset_sum(i-1, sum-val[i]);
        int op2 = subset_sum(i-1, sum);

        dp[i][sum] = op1 + op2;
        return dp[i][sum];
    }
    else
    {
        dp[i][sum] = subset_sum(i-1, sum);
        return dp[i][sum];
    }
}

void printans(int i, int sum)
{
    if(i < 0)
    {
        if(sum == 0)
        {
            for(int j = 0; j < 5; j++)
                cout << ans[j] << " ";

            cout << endl;
        }
        return;
    }

    if(val[i] <= sum && subset_sum(i-1, sum-val[i]) > 0)
    {
        ans[i] = 1;
        printans(i-1, sum-val[i]);
    }

    if(subset_sum(i-1, sum) > 0)
    {
        ans[i] = 0;
        printans(i-1, sum);
    }
}


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> val[i];

    int sum;
    cin >> sum;
    memset(dp, -1, sizeof(dp));
    int total = subset_sum(n-1, sum);
    cout << "Number of subsets = " << total << endl;
    cout << "Solutions:" << endl;
    printans(n-1, sum);
    return 0;
}