#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &a, int x)
{
    int l = 0, r = a.size() - 1;
    int ans = a.size();

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (a[mid] >= x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

int upperBound(vector<int> &a, int x)
{
    int l = 0, r = a.size() - 1;
    int ans = a.size();

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (a[mid] > x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
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

    int lb = lowerBound(a, x);
    int ub = upperBound(a, x);

    cout << "Lower Bound Index = " << lb << endl;
    cout << "Upper Bound Index = " << ub << endl;

    if (lb == n || a[lb] != x)
    {
        cout << "Frequency = 0" << endl;
    }
    else
    {
        cout << "Frequency = " << ub - lb << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> a = {1, 2, 2, 2, 4, 5, 7};

//     int x = 2;

//     int lb = lower_bound(a.begin(), a.end(), x) - a.begin();
//     int ub = upper_bound(a.begin(), a.end(), x) - a.begin();

//     cout << "Lower Bound = " << lb << endl;
//     cout << "Upper Bound = " << ub << endl;
// }