#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool vis[100005];
int cnt = 0;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

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

    vector<int> v;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
            v.push_back(i);
            cnt++;
        }
    }
    cout << cnt - 1 << endl;
    if (cnt - 1 != 0)
    {
        for (int i = 1; i < v.size(); i++)
        {
            cout << v[i - 1] << " " << v[i] << "\n";
        }
    }
    return 0;
}