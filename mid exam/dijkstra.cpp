#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[105];
int dis[105];
int parent[105];

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> par = pq.top();pq.pop();

        int par_node = par.second;
        int par_dis = par.first;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                parent[child_node] = par_node;
                pq.push({dis[child_node], child_node});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj_list[a].push_back({b, c});
    }

    //memset(parent, -1, sizeof(parent));

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
        parent[i]=-1;
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        if (dis[i] == INT_MAX)
        {
            cout << "0 -> " << i << " : IMPOSSIBLE\n";
            continue;
        }

        cout << "Source = 0, Destination = " << i << endl;
        cout << "Cost = " << dis[i] << endl;

        vector<int> path;
        int node = i;

        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }

        reverse(path.begin(), path.end());

        cout << "Path : ";
        for (int x : path)
            cout << x << " ";

        cout << "\n\n";
    }

    return 0;
}