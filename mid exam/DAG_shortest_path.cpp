#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1005];
bool vis[1005];
stack<int> st;
int dist[1005];

void dfs(int src)
{
    vis[src]=true;

    for(auto child:adj[src])
    {
        if(!vis[child.first])
            dfs(child.first);
    }
    st.push(src);
}

int main()
{
    int n,e;
    cin>>n>>e;

    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
    }

    memset(vis,false,sizeof(vis));

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(i);
    }

    for(int i=0;i<n;i++)
        dist[i]=INT_MAX;

    int src=0;
    dist[src]=0;

    while(!st.empty())
    {
        int u=st.top();
        st.pop();

        if(dist[u]!=INT_MAX)
        {
            for(auto edge:adj[u])
            {
                int v=edge.first;
                int w=edge.second;

                if(dist[u]+w<dist[v])
                    dist[v]=dist[u]+w;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(dist[i]==INT_MAX)
            cout<<"INF ";
        else
            cout<<dist[i]<<" ";
    }
}