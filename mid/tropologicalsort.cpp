#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
stack<int> s;
void dfs(int src)
{
    // cout << src << " ";
    vis[src] = true;
    for (int child : adj_list[src])
        if (!vis[child])
            dfs(child);

    s.push(src);
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
    }
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}