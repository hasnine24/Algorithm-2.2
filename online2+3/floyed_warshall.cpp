#include <bits/stdc++.h>
#include <windows.h>
#include <psapi.h>
#pragma comment(lib, "Psapi.lib")
#define CPU_POWER_WATTS 65.0
#define BD_EMISSION_FACTOR 0.62
using namespace std;

int main()
{
    freopen("sparse.txt", "r", stdin);
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
    int n,e;
    cin >> n >> e;
    int adj_mat[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
            {
                adj_mat[i][j] = 0;
            }
            else
            {
                adj_mat[i][j] = INT_MAX;
            }
        }
    }

    while(e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(adj_mat[i][k]!=INT_MAX && adj_mat[k][j]!=INT_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
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

