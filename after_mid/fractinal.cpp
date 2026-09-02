#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (double)a.first / a.second >(double)b.first / b.second;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a;

    for(int i = 0; i < n; i++)
    {
        int value, weight;
        cin >> value >> weight;
        a.push_back({value, weight});
    }

    int W;
    cin >> W;

    sort(a.begin(), a.end(), cmp);

    double profit = 0;

    for(int i = 0; i < n; i++)
    {
        if(W >= a[i].second)
        {
            W =W-a[i].second;
            profit =profit + a[i].first;
        }
        else
        {
            profit = profit + (double)a[i].first / a[i].second * W;
            break;
        }
    }

    cout << "Maximum Profit = " << profit << endl;

    return 0;
}