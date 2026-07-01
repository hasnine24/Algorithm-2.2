#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool vis[100005];
int team[100005];
bool ok = true;

void dfs(int src)
{
    vis[src] = true;

    for (int child : adj_list[src])
    {
        if (!vis[child])
        {
            team[child] = 3 - team[src]; // 1 -> 2, 2 -> 1
            dfs(child);
        }
        else if (team[child] == team[src])
        {
            ok = false;
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
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            team[i] = 1;
            dfs(i);
        }
    }

    if (!ok)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
            cout << team[i] << " ";
    }

    return 0;
}