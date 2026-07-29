#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[105];
int dis[105][2];       // dis[node][0] = discount বাকি আছে, dis[node][1] = discount ব্যবহার হয়ে গেছে
pair<int,int> parent_[105][2]; // parent[node][state] = {parent_node, parent_state}

void dijkstra(int src, int n)
{
    // pq entry: {cost, {node, state}}
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;

    pq.push({0, {src, 0}});
    dis[src][0] = 0;

    while (!pq.empty())
    {
        auto par = pq.top(); pq.pop();

        int par_dis   = par.first;
        int par_node  = par.second.first;
        int par_state = par.second.second;

        if (par_dis > dis[par_node][par_state]) continue; // stale entry skip

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_cost = child.second;

            // ---- Option 1: discount ব্যবহার না করে যাও (state অপরিবর্তিত থাকবে) ----
            if (par_dis + child_cost < dis[child_node][par_state])
            {
                dis[child_node][par_state] = par_dis + child_cost;
                parent_[child_node][par_state] = {par_node, par_state};
                pq.push({dis[child_node][par_state], {child_node, par_state}});
            }

            // ---- Option 2: এই edge-এ discount ব্যবহার করো (শুধু par_state==0 হলে সম্ভব) ----
            if (par_state == 0)
            {
                int half = child_cost / 2;
                if (par_dis + half < dis[child_node][1])
                {
                    dis[child_node][1] = par_dis + half;
                    parent_[child_node][1] = {par_node, 0};
                    pq.push({dis[child_node][1], {child_node, 1}});
                }
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

    for (int i = 0; i <= n; i++)
    {
        dis[i][0] = INT_MAX;
        dis[i][1] = INT_MAX;
        parent_[i][0] = {-1, -1};
        parent_[i][1] = {-1, -1};
    }

    dijkstra(1, n); // CSES-এ 1-indexed, city 1 থেকে শুরু

    // উত্তর হলো dis[n][1] -> discount ব্যবহার করে city n এ পৌঁছানোর সর্বনিম্ন খরচ
    cout << "Minimum cost = " << dis[n][1] << "\n";
    return 0;
}