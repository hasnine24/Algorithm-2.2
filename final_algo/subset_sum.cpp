#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> w;
vector<int> x;

void SumOfSub(int s, int k, int r)
{
    x[k] = 1;
    if (s + w[k] == m)
    {
        for (int i = 1; i <= k; i++)
        {
            if (x[i] == 1)
                cout << w[i] << " ";
        }cout<<endl;
    }
    else if (s + w[k] + w[k + 1] <= m)
    {
        SumOfSub(s + w[k], k + 1, r - w[k]);
    }
    //right
    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m))
    {
        x[k] = 0;
        SumOfSub(s, k + 1, r - w[k]);
    }
}
int main()
{
    cin >> n;
    w.resize(n + 2);
    x.resize(n + 2);

    for (int i = 1; i <= n; i++)
        cin >> w[i];

    cin >> m;
    int total = 0;
    for (int i = 1; i <= n; i++)
        total += w[i];

    // Sentinel value
    w[n + 1] = INT_MAX;
    cout <<"Subsets sum " << m <<endl;
    SumOfSub(0, 1, total);
    return 0;
}