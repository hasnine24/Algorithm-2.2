#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int dis[1005];
int parent[1005];
vector<Edge> edge_list;
int n, e;

bool bellman_ford()
{
    // Relax n-1 times
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
                parent[b] = a;
            }
        }
    }

    int x = -1;

    // N-th relaxation
    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        int c = ed.c;

        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            parent[b] = a;
            x = b;
            break;
        }
    }

    if (x == -1)
        return false;

    // Move inside the cycle
    for (int i = 0; i < n; i++)
        x = parent[x];

    vector<int> cycle;

    int cur = x;

    while (true)
    {
        cycle.push_back(cur);
        cur = parent[cur];

        if (cur == x)
        {
            cycle.push_back(x);
            break;
        }
    }

    reverse(cycle.begin(), cycle.end());

    cout << "Negative Cycle: ";

    for (int node : cycle)
        cout << node << " ";

    cout << endl;

    return true;
}

int main()
{
    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
        parent[i] = -1;
    }

    dis[0] = 0;

    if (!bellman_ford())
    {
        cout << "No Negative Cycle\n";
    }

    return 0;
}