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

    for (int i = 0; i < n;)
    {
        int first = firstOcc(a, a[i]);
        int last = lastOcc(a, a[i]);

        if (first != last)
            cout << a[i] << " ";

        i = last + 1; // next unique element
    }
}