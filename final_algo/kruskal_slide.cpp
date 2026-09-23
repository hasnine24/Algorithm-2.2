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

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int parent[100];

int FindSet(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    else
    {
        return parent[v] = FindSet(parent[v]);
    }
}

void Union(int a, int b)
{
    a = FindSet(a);
    b = FindSet(b);
    if (a != b)
    {
        parent[b] = a;
    }
}

int main()
{
    int n, e;cin >> n >> e;
    vector<Edge> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    // MakeSet
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    // Sort according to weight
    sort(edges.begin(), edges.end(), cmp);
    int totalCost = 0;
    int count = 0;
    cout << "MST Edges:"<<endl;
    for (Edge e : edges)
    {
        if (FindSet(e.u) != FindSet(e.v))
        {
            cout << e.u << " - "<< e.v << " : "<< e.w << endl;
            totalCost += e.w;
            count++;
            Union(e.u, e.v);
            if (count == n - 1)
            {
                break;
            }
        }
    }
    cout << "Minimum Cost = " << totalCost << endl;
    return 0;
}