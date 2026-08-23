#include <bits/stdc++.h>
#include <windows.h>
#include <psapi.h>
#pragma comment(lib, "Psapi.lib")
#define CPU_POWER_WATTS 65.0
#define BD_EMISSION_FACTOR 0.62
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;
vector<pair<int, int>> adj_list[1005];

int dis[1005];
int h[1005];
int answer[1005][1005];
int n, e;

bool bellman_ford()
{
    for (int i = 0; i < n; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if (h[a] + c < h[b])
            {
                h[b] = h[a] + c;
                if (i == n - 1)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();

        int par_node = par.second;
        int par_dis = par.first;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
            }
        }
    }
}
int main()
{
    freopen("sparse.txt", "r", stdin);
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }
    //new node add
    for (int i = 0; i < n; i++)
    {
        edge_list.push_back(Edge(n, i, 0));
    }
    //bellman ford
    if (!bellman_ford())
    {
        cout << "Negative cycle detected"<<endl;
        return 0;
    }
    //reweight graph
    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        int c = ed.c;

        if (a == n)
        {
            continue;
        }
        int new_cost = c + h[a] - h[b];
        adj_list[a].push_back({b, new_cost});
    }
    //dijkstra
    for (int src = 0; src < n; src++)
    {
        for (int i = 0; i < n; i++)
        {
            dis[i] = INT_MAX;
        }
        dijkstra(src);

        for (int dest = 0; dest < n; dest++)
        {
            if (dis[dest] == INT_MAX)
            {
                answer[src][dest] = INT_MAX;
            }
            else
            {
                answer[src][dest] = dis[dest] - h[src] + h[dest];
            }
        }
    }

    QueryPerformanceCounter(&end);
    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    double energy = CPU_POWER_WATTS * elapsed;    // Joules
    double energy_kWh = energy / 3.6e6;           // kWh
    double co2 = energy_kWh * BD_EMISSION_FACTOR; // kg CO₂
    // ----- Memory usage -----
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc)))
    {
        SIZE_T peakMemUsed = pmc.PeakWorkingSetSize; // Peak RAM usage

        printf("Execution time: %.6f seconds\n", elapsed);
        printf("Estimated energy consumption: %.2f Joules\n", energy);
        printf("Peak Memory Usage: %zu KB\n", peakMemUsed / 1024);
        printf("Estimated CO2 emissions (Bangladesh): %.8f kg\n", co2);
    }
    else
    {
        printf("Failed to get memory info.\n");
    }
    return 0;
}

