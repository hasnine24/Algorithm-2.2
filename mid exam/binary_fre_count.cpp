#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> &a, int x)
{
    int l = 0, r = a.size() - 1;
    int ans = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (a[mid] == x)
        {
            ans = mid;
            r = mid - 1;
        }
        else if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return ans;
}

int lastOcc(vector<int> &a, int x)
{
    int l = 0, r = a.size() - 1;
    int ans = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (a[mid] == x)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x;
    cin >> x;

    int first = firstOcc(a, x);

    if (first == -1)
    {
        cout << "Frequency = 0";
        return 0;
    }

    int last = lastOcc(a, x);

    cout << "Frequency = " << last - first + 1;
}