#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<int, int>> adj[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    priority_queue<pair<ll, int>,vector<pair<ll, int>>,greater<pair<ll, int>>> pq;

    vector<int> cnt(n + 1, 0);

    pq.push({0, 1});

    while (!pq.empty())
    {
        pair<ll, int> par = pq.top();
        pq.pop();

        ll par_dis = par.first;
        int par_node = par.second;

        cnt[par_node]++;

        if (cnt[par_node] > k)
            continue;

        if (par_node == n)
            cout << par_dis << " ";

        for (auto child : adj[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (cnt[child_node] < k)
            {
                pq.push({par_dis + child_dis, child_node});
            }
        }
    }

    return 0;
}