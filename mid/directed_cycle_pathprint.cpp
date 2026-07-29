#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[100005];
bool vis[100005];
bool pathVis[100005];
int parent[100005];

int startNode = -1, endNode = -1;

bool dfs(int src)
{
    vis[src] = true;
    pathVis[src] = true;

    for(int child : adj_list[src])
    {
        if(!vis[child])
        {
            parent[child] = src;

            if(dfs(child))
                return true;
        }
        else if(pathVis[child])
        {
            startNode = child;
            endNode = src;
            return true;
        }
    }

    pathVis[src] = false;
    return false;
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
    }

    memset(vis,false,sizeof(vis));
    memset(pathVis,false,sizeof(pathVis));
    memset(parent,-1,sizeof(parent));

    bool found = false;

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i))
            {
                found = true;
                break;
            }
        }
    }

    if(!found)
    {
        cout << "No Cycle\n";
    }
    else
    {
        vector<int> cycle;

        cycle.push_back(startNode);

        int cur = endNode;

        while(cur != startNode)
        {
            cycle.push_back(cur);
            cur = parent[cur];
        }

        cycle.push_back(startNode);

        reverse(cycle.begin(), cycle.end());

        cout << "Cycle Detected\n";
        cout << "Cycle Path : ";

        for(int x : cycle)
            cout << x << " ";
    }

    return 0;
}