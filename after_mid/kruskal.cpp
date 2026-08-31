#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, w;

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

vector<int> parent;

// Find operation
int FindSet(int u)
{
    if (parent[u] == u)
        return u;

    return parent[u] = FindSet(parent[u]);
}

// Union operation
void Union(int u, int v)
{
    u = FindSet(u);
    v = FindSet(v);

    if (u != v)
        parent[v] = u;
}
bool cmp(Edge l,Edge r)
{
    return l.w<r.w;
}
int main()
{
    int V, E;
    cin >>V>> E;
    vector<Edge> edges;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    // MakeSet(v)
    parent.resize(V + 1);

    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(),cmp);
    vector<Edge> MST;
    int totalWeight = 0;
    // Main Kruskal loop
    for (auto edge : edges)
    {
        int u = edge.u;
        int v = edge.v;

        // FindSet(u) != FindSet(v)
        if (FindSet(u) != FindSet(v))
        {
            MST.push_back(edge);

            totalWeight += edge.w;
            // Union
            Union(u, v);
        }
    }

    // Print MST
    cout << "\nMinimum Spanning Tree:\n";

    for (auto edge : MST)
    {
        cout << edge.u << " - "
             << edge.v << " : "
             << edge.w << endl;
    }

    cout << "Total Weight = " << totalWeight << endl;

    return 0;
}