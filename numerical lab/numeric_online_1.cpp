#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return sin(x) + exp(-x) - x/5.0;
}

void bisection(double a, double b, double tol, int maxIter)
{
    if (f(a) * f(b) >= 0)
    {
        cout << "Invalid interval\n";
        return;
    }

    double c;

    for (int i = 1; i <= maxIter; i++)
    {
        c = (a + b) / 2.0;

        cout << i << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << "\n";

        if (fabs(f(c)) < tol)
            break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "Root = " << c << "\n";
}

void falsePosition(double a, double b, double tol, int maxIter)
{
    if (f(a) * f(b) >= 0)
    {
        cout << "Invalid interval\n";
        return;
    }

    double c;

    for (int i = 1; i <= maxIter; i++)
    {
        c = a - (f(a) * (b - a)) / (f(b) - f(a));

        cout << i << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << "\n";

        if (fabs(f(c)) < tol)
            break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "Root = " << c << "\n";
}

int main()
{
    double a, b, tol;
    int maxIter;

    cin >> a >> b >> tol >> maxIter;

    bisection(a, b, tol, maxIter);
    falsePosition(a, b, tol, maxIter);

    return 0;
}