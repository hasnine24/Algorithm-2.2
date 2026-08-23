#include <bits/stdc++.h>
using namespace std;
#define EPS 0.00001
double f(double x)
{
    return x*x*x*x - 3*x*x*x - 3*x*x + 11*x - 6;
}
int main()
{
    double an = 1;
    double an1 = -3;
    double an2 = -3;
    double R = sqrt(pow(an1 / an, 2) - 2 * (an2 / an));
    double a = -R;
    double b = R;
    double ds = 0.1;
    cout << fixed << setprecision(6);
    cout << "Search Bracket: ["<< a << ", " << b << "]<<endl";
    double x1 = a;
    double x2 = x1 + ds;
    int rootNo = 0;
    while (x2 <= b)
    {
        double f1 = f(x1);
        double f2 = f(x2);
        if (f1 * f2 < 0)
        {
            double error = 1e9;
            double prev_root = x1;
            double x0;
            cout << "Converging to Root (root no): "<< rootNo + 1 << endl;
            cout << "Iter\t x0\t\t Error\n";
            int i = 0;
            while (error >= EPS)
            {
                i++;
                x0 = (x1 + x2) / 2.0;
                error = fabs(x0 - prev_root);
                cout << i << "\t"<< x0 << "\t"<< error << "\n";
                if (f(x0) == 0)
                {
                    break;
                }
                if (f(x0) * f(x1) < 0)
                {
                    x2 = x0;
                }
                else
                {
                    x1 = x0;
                }
                prev_root = x0;
            }
            rootNo++;
            double root = x0;
            root = round(root);
            cout << "Root = "<< root << "\n";
        }
        x1 = x2;
        x2 = x1 + ds;
    }
    return 0;
}