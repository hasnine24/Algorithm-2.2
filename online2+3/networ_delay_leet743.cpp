#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int, int>> adj[n + 1];
    for (auto& edge : times) {
        adj[edge[0]].push_back({edge[1], edge[2]}); // u -> {v, weight}
    }

    vector<int> dist(n + 1, 1e9);
    // Min-heap: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& child : adj[u]) {
            int v = child.first;
            int w = child.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 1e9) return -1;
        max_time = max(max_time, dist[i]);
    }
    return max_time;
}

int main() {
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    cout << "Max Time: " << networkDelayTime(times, n, k) << "\n";
    return 0;
}