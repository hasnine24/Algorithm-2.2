#include <bits/stdc++.h>
using namespace std;

int par[1005];
int weight[1005];
bool vis[1005];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> adj[1005];
    vector<pair<int, int>> mst;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    memset(par, -1, sizeof(par));
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        weight[i] = INT_MAX;
    }

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    weight[0] = 0;
    pq.push({0, 0});

    int totalcost = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (vis[u])
            continue;

        vis[u] = true;

        if (par[u] != -1)
        {
            mst.push_back({par[u], u});
        }

        totalcost += w;

        for (auto x : adj[u])
        {
            int v = x.first;
            int edgeWeight = x.second;

            if (!vis[v] && edgeWeight < weight[v])
            {
                weight[v] = edgeWeight;
                par[v] = u;
                pq.push({weight[v], v});
            }
        }
    }

    cout << "MST Edges:\n";

    for (auto x : mst)
    {
        cout << x.first << " - " << x.second << endl;
    }

    cout << "Total Cost = " << totalcost << endl;

    return 0;
}