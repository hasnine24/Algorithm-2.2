#include <bits/stdc++.h>
using namespace std;
#define EPS 0.0001
double f(vector<double> &a, int n, double x)
{
    double result = a[0];
    for (int i = 1; i <= n; i++)
    {
        result = result * x + a[i];
    }
    return result;
}
double df(vector<double> &a, int n, double x)
{
    double result = a[0] * n;
    for (int i = 1; i < n; i++)
    {
        result = result * x + a[i] * (n - i);
    }
    return result;
}
int main()
{
    vector<double> a = {1, -3, -3, 11, -6};
    int n = 4;
    double x0 = 2.5;
    cout << fixed << setprecision(6);
    int rootNo = 1;
    while (n > 1)
    {
        double e = 1e9;
        double x1;
        cout << "Converging to Root " << rootNo <<endl;
        cout << "Iter\t x0\t\t f(x0)\t\t f'(x0)\t x1\t\t Error"<<endl;
        int it = 0;
        while (e >= EPS)
        {
            it++;
            double f1 = f(a, n, x0);
            double f2 = df(a, n, x0);
            x1 = x0 - f1 / f2;
            e = fabs(x1 - x0);
            cout << it << "\t"<< x0 << "\t"<< f1 << "\t"<< f2 << "\t"<< x1 << "\t"<< e <<endl;
            x0 = x1;
        }
        x0 = round(x0);
        cout << "Root = " << x0 <<endl;
        vector<double> b(n);
        b[0] = a[0];
        int i = 1;
        while (i < n)
        {
            b[i] = a[i] + b[i - 1] * x0;
            i++;
        }
        i = 0;
        while (i < n)
        {
            a[i] = b[i];
            i++;
        }
        n--;
        rootNo++;
    }
    double root = -a[1] / a[0];
    root = round(root);
    cout << "Root = "<< root << endl;
    return 0;
}