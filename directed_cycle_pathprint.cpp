#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
bool pathVis[105];
vector<int> path;
vector<int> cycle;

bool dfs(int src)
{
    vis[src] = true;
    pathVis[src] = true;
    path.push_back(src);

    for(int child : adj_list[src])
    {
        if(!vis[child])
        {
            if(dfs(child))
                return true;
        }
        else if(pathVis[child])
        {
            int i;
            for(i = path.size()-1; i >= 0; i--)
            {
                cycle.push_back(path[i]);
                if(path[i] == child)
                    break;
            }
            reverse(cycle.begin(), cycle.end());
            cycle.push_back(child);   // complete the cycle
            return true;
        }
    }

    path.pop_back();
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

    bool found = false;

    for(int i=0;i<n;i++)
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

    if(found)
    {
        cout << "Cycle Detected\n";
        cout << "Cycle Path : ";
        for(int x : cycle)
            cout << x << " ";
    }
    else
    {
        cout << "No Cycle\n";
    }

    return 0;
}