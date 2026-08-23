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

vector<Edge> edge_list;
vector<pair<int, int>> adj_list[105];

int dis[105];
int h[105];
int answer[105][105];
int n, e;

bool bellman_ford()
{
    for (int i = 0; i < n; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if (h[a] + c < h[b])
            {
                h[b] = h[a] + c;
                if (i == n - 1)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

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
                pq.push({dis[child_node], child_node});
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
    }
    //original graph
    for (int i = 0; i < n; i++)
    {
        edge_list.push_back(Edge(n, i, 0));
    }
    //bellman ford 
    if (!bellman_ford())
    {
        cout << "Negative cycle detected"<<endl;
        return 0;
    }
    //reweight graph
    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        int c = ed.c;

        int new_cost = c + h[a] - h[b];
        adj_list[a].push_back({b, new_cost});
    }
    //dijkstra
    for (int src = 0; src < n; src++)
    {
        for (int i = 0; i < n; i++)
        {
            dis[i] = INT_MAX;
        }
        dijkstra(src);

        for (int dest = 0; dest < n; dest++)
        {
            if (dis[dest] == INT_MAX)
            {
                answer[src][dest] = INT_MAX;
            }
            else
            {
                answer[src][dest] = dis[dest] - h[src] + h[dest];
            }
        }
    }
    //print mattrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (answer[i][j] == INT_MAX)
            {
                cout << "N"<<" ";
            }
            else
            {
                cout << answer[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}