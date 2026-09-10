#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[105];
int dis[105];

int dijkstra(int src, int dst, int k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {src, 0}});

    while (!pq.empty())
    {
        auto par = pq.top();pq.pop();

        int par_dis = par.first;
        int par_node = par.second.first;
        int stops_count = par.second.second;

        //base case
        if (par_node == dst)
        {
            return par_dis;
        }

        // যদি আগে একই নোডে কম বা সমান স্টপ দিয়ে পৌঁছে থাকি, তবে স্কিপ
        if (stops_count >= dis[par_node])
        {
            continue;
        }
        dis[par_node] = stops_count;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            // সর্বোচ্চ k টি স্টপ (অর্থাৎ সর্বোচ্চ k টি স্টপ দিয়ে যেতে পারবো)
            if (stops_count <= k)
            {
                pq.push({par_dis + child_dis, {child_node, stops_count + 1}});
            }
        }
    }
    return -1;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    int src, dst, k;
    cin >> src >> dst >> k;

    int ans = dijkstra(src, dst, k);

    if (ans == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << "Cheapest Cost = " << ans << "\n";
    }

    return 0;
}