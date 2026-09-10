#include<bits/stdc++.h>
#include <windows.h>
#include <psapi.h>
#pragma comment(lib, "Psapi.lib")
#define CPU_POWER_WATTS 65.
#define BD_EMISSION_FACTOR 0.62

using namespace std;

void insertion_sort(vector<int>& arr)
{
    for(int i=1; i<arr.size(); i++)
    {
        int key=arr[i];
        int pre=i-1;
        while(pre>=0&&arr[pre]>key)
        {
            arr[pre+1]=arr[pre];
            pre--;
        }
        arr[pre+1]=key;
    }
}
int main()
{
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    vector<int>arr;
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
    insertion_sort(arr);

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
