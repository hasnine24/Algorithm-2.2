#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Horner's Method
double horner(double a[], int degree, double x)
{
    double result = a[0];

    for (int i = 1; i <= degree; i++)
        result = result * x + a[i];

    return result;
}

int main()
{
    // 2x^4 - 9x^3 + 7x^2 - 5x + 6
    double coeff[] = {2, -9, 7, -5, 6};
    int degree = 4;

    // Initial Guess
    double x0 = -coeff[1] / (2 * coeff[0]);
    double x1 = x0 + 0.5;

    cout << fixed << setprecision(6);

    cout << "Initial Guess: " << x0 << "\n\n";

    cout << "No\t"
         << "x0\t\t"
         << "x1\t\t"
         << "f(x0)\t\t"
         << "f(x1)\t\t"
         << "x2\t\t"
         << "f(x2)\t\t"
         << "Sign\t\t"
         << "Abs Error\n";

    int iter = 1;

    while (true)
    {
        double fx0 = horner(coeff, degree, x0) / 4.0;
        double fx1 = horner(coeff, degree, x1) / 4.0;

        double x2 = x1 - (fx1 * (x1 - x0)) / (fx1 - fx0);

        double fx2 = horner(coeff, degree, x2) / 4.0;

        double err = fabs(x2 - x1);

        cout << iter << "\t"
             << x0 << "\t"
             << x1 << "\t"
             << fx0 << "\t"
             << fx1 << "\t"
             << x2 << "\t"
             << fx2 << "\t";

        if (fx2 > 0)
            cout << "+\t";
        else if (fx2 < 0)
            cout << "-\t";
        else
            cout << "0\t";

        if (iter == 1)
            cout << "N/A\n";
        else
            cout << err << "\n";

        if (err < 0.000001)
            break;

        x0 = x1;
        x1 = x2;
        iter++;
    }

    cout << "\nTotal Iterations: " << iter << endl;
    cout << "Approximate Root = " << x1 << endl;

    return 0;
}