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

void bellman_ford()
{
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
                parent[b] = a;          // Parent update
            }
        }
    }
}

int main()
{
    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edge_list.push_back(Edge(a, b, c));
        // edge_list.push_back(Edge(b, a, c)); // Undirected
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
        parent[i] = -1;
    }

    dis[0] = 0;

    bellman_ford();

    for (int i = 0; i < n; i++)
    {
        if (dis[i] == INT_MAX)
        {
            cout << "0 -> " << i << " : IMPOSSIBLE\n\n";
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