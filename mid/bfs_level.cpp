#include<bits/stdc++.h>
using namespace std;
bool vis[105];
vector<int> adj_list[105];
int level[105];
int parent[105];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src]=0;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        //cout<<par<<endl;
        for(int child : adj_list[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child]=level[par]+1;
                parent[child]=par;
            }
        }
    }
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            bfs(i);
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<i<<"->"<<level[i]<<"->"<<parent[i]<<endl;
    // }
    int node=8;
    while(node!=-1)
    {
        cout<<node<<" ";
        node=parent[node];
    }

    return 0;
}