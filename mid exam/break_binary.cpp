#include <bits/stdc++.h>
using namespace std;

int peakIndex(vector<int>& a)
{
    int l = 0;
    int r = a.size() - 1;

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] < a[mid + 1])
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}

int main()
{
    vector<int> a = {1,3,5,7,6,4,2};

    int idx = peakIndex(a);

    cout << "Peak Index = " << idx << endl;
    cout << "Peak Value = " << a[idx] << endl;
}