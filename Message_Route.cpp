#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool vis[100005];
int level[100005];
int parent[100005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 1;

    while (!q.empty())
    {
        // ber kore ana
        int par = q.front();
        q.pop();

        // oi node ke niye kaj
        // cout << par << " ";

        // children gulo push kora
        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
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
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    bfs(1);
    if (level[n] != -1)
    {
        cout << level[n] << endl;
        vector<int> v;
        int node = n;
        while (node != -1)
        {
            v.push_back(node);
            node = parent[node];
        }
        reverse(v.begin(), v.end());
        for (auto it : v)
        {
            cout << it << " ";
        }
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}