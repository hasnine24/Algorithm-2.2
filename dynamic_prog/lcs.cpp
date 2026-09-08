#include <bits/stdc++.h>
using namespace std;

string a, b;
int dp[1005][1005];

int lcs(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i] == b[j])
    {
        return dp[i][j] = lcs(i - 1, j - 1) + 1;
    }
    else
    {
        int op1 = lcs(i - 1, j);
        int op2 = lcs(i, j - 1);
        return dp[i][j] = max(op1,op2);
    }
}

string printlcs(int i, int j)
{
    if (i < 0 || j < 0)
        return "";

    if (a[i] == b[j])
    {
        return printlcs(i - 1, j - 1) + a[i];
    }
    else
    {
        int op1 = lcs(i - 1, j);
        int op2 = lcs(i, j - 1);
        if (op1 >= op2)
            return printlcs(i - 1, j);
        else
            return printlcs(i, j - 1);
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int length = lcs(n - 1, m - 1);
    string ans = printlcs(n - 1, m - 1);
    cout << "LCS length: " << length << endl;
    cout << "LCS: " << ans << endl;
    return 0;
}