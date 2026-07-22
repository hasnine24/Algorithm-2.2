#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = LLONG_MAX;

vector<pair<int, int>> adj_list[200005];
ll dis[200005][2];

void dijkstra(int src)
{
    priority_queue<pair<ll, pair<int, int>>,vector<pair<ll, pair<int, int>>>,greater<pair<ll, pair<int, int>>>> pq;

    dis[src][0] = 0;
    pq.push({0, {src, 0}});

    while (!pq.empty())
    {
        pair<ll, pair<int, int>> par = pq.top();
        pq.pop();

        ll par_dis = par.first;
        int par_node = par.second.first;
        int state = par.second.second;

        if (par_dis > dis[par_node][state])
            continue;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (state == 0)
            {
                // Discount use না করে
                if (par_dis + child_dis < dis[child_node][0])
                {
                    dis[child_node][0] = par_dis + child_dis;
                    pq.push({dis[child_node][0], {child_node, 0}});
                }

                // এই edge-এ discount use করে
                if (par_dis + child_dis / 2 < dis[child_node][1])
                {
                    dis[child_node][1] = par_dis + child_dis / 2;
                    pq.push({dis[child_node][1], {child_node, 1}});
                }
            }
            else
            {
                // Discount already used
                if (par_dis + child_dis < dis[child_node][1])
                {
                    dis[child_node][1] = par_dis + child_dis;
                    pq.push({dis[child_node][1], {child_node, 1}});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // Directed Graph
        adj_list[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i][0] = INF;
        dis[i][1] = INF;
    }

    dijkstra(1);

    cout << dis[n][1] << "\n";

    return 0;
}