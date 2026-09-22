#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int n;cin >> n;

    vector<pair<int, int>> a;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start>> end;
        a.push_back({start, end});
    }

    sort(a.begin(), a.end(), cmp);

    int count = 1;
    int lastFinish = a[0].second;

    cout << "(" << a[0].first << ", "
         << a[0].second << ")" << endl;

    for (int i = 1; i < n; i++)
    {
        if (a[i].first >= lastFinish)
        {
            cout << "(" << a[i].first << ", "<< a[i].second << ")" << endl;
            lastFinish = a[i].second;
            count++;
        }
    }
    cout << "Maximum activities = " << count << endl;
    return 0;
}