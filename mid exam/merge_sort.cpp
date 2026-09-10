#include<bits/stdc++.h>
#include <windows.h>
#include <psapi.h>
#pragma comment(lib, "Psapi.lib")
#define CPU_POWER_WATTS 65.
#define BD_EMISSION_FACTOR 0.62

using namespace std;

void merge(vector<int>&a, int l, int mid, int r)
{
    int n = mid - l + 1;
    int m = r - mid;
    int b[n], c[m];

    for (int i = 0; i < n; i++)
    {
        b[i] = a[l + i];
    }

    for (int i = 0; i < m; i++)
    {
        c[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0, curr = l;

    while (i < n && j < m)
    {
        if (b[i] < c[j])
        {
            a[curr] = b[i];
            i++;
        }
        else
        {
            a[curr] = c[j];
            j++;
        }
        curr++;
    }

    while (i < n)
    {
        a[curr] = b[i];
        i++;
        curr++;
    }

    while (j < m)
    {
        a[curr] = c[j];
        j++;
        curr++;
    }
}
void divide(vector<int>& a, int l, int r)
{
    if (l < r)
    {

        int mid = (l + r) / 2;
        divide(a, l, mid);
        divide(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}
int main()
{
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    vector<int> arr;
    FILE *f = fopen("sorted_random.txt", "r");
    if(f == NULL)
    {
        cout<<"File Error"<<endl;
        return 1;
    }
    int x;
    while(fscanf(f, "%d", &x) == 1)
    {
        arr.push_back(x);
    }
    fclose(f);
    divide(arr, 0, arr.size() - 1);

    QueryPerformanceCounter(&end);
    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    double energy = CPU_POWER_WATTS * elapsed;         // Joules
    double energy_kWh = energy / 3.6e6;                // kWh
    double co2 = energy_kWh * BD_EMISSION_FACTOR;      // kg CO₂

    // ----- Memory usage -----
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc)))
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
