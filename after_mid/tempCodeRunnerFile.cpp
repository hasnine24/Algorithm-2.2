
        for (auto x : adj[v])
        {
            int u = x.first;
            int w = x.second;

            if (!vis[u] && w < weight[u])
            {
                weight[u] = w;
                par[u] = v;

                pq.push({weight[u], u});
            }
        }