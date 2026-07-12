#include <bits/stdc++.h>
#include <windows.h>
#include <psapi.h>
#pragma comment(lib, "Psapi.lib")
#define CPU_POWER_WATTS 65.0
#define BD_EMISSION_FACTOR 0.62
using namespace std;

bool binary_srch(vector<string> &src, string word)
{
    int l = 0, r = src.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (src[mid] == word)
            return true;
        else if (src[mid] < word)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}
int main()
{
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    vector<string> src;
    vector<string> words;
    int n, m;
    ifstream f1("searchspace.txt");
    string s1;
    f1 >> n;
    while (f1 >> s1)
    {
        src.push_back(s1);
    }
    f1.close();
    ifstream f2("wordspace.txt");
    string s2;
    f2 >> m;
    while (f2 >> s2)
    {
        words.push_back(s2);
    }
    f2.close();
    for (int i = 0; i < words.size(); i++)
    {
        binary_srch(src, words[i]);
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
