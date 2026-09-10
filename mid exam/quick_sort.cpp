#include<bits/stdc++.h>
#include <windows.h>
#include <psapi.h>
#pragma comment(lib, "Psapi.lib")
#define CPU_POWER_WATTS 65.0
#define BD_EMISSION_FACTOR 0.62

using namespace std;

int partition(vector<int>&a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while(true)
    {
        while(i <= high && a[i] <= pivot)
        {
            i++;
        }

        while(j >= low && a[j] > pivot)
        {
            j--;
        }

        if(i >= j)
        {
            break;
        }

        swap(a[i], a[j]);
    }
    swap(a[low], a[j]);
    return j;
}

void quickSort(vector<int>&a, int low, int high)
{
    if(low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
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
    quickSort(arr, 0, arr.size() - 1);

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
