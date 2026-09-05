#include <iostream>
#include <cmath>
using namespace std;

void jacobi(double a[][10], double b[], int n)
{
    double x[10] = {0};
    double newX[10];
    double error, tolerance = 0.0001;

    for (int iter = 1; iter <= 100; iter++)
    {
        error = 0;

        for (int i = 0; i < n; i++)
        {
            double sum = 0;

            for (int j = 0; j < n; j++)
            {
                if (j != i)
                    sum += a[i][j] * x[j];
            }

            newX[i] = (b[i] - sum) / a[i][i];

            error = max(error, fabs(newX[i] - x[i]));
        }

        for (int i = 0; i < n; i++)
            x[i] = newX[i];

        if (error < tolerance)
            break;
    }

    cout << "\nJacobi Solution:\n";

    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << x[i] << endl;
}


void gaussSeidel(double a[][10], double b[], int n)
{
    double x[10] = {0};
    double error, tolerance = 0.0001;

    for (int iter = 1; iter <= 100; iter++)
    {
        error = 0;

        for (int i = 0; i < n; i++)
        {
            double sum = 0;

            for (int j = 0; j < n; j++)
            {
                if (j != i)
                    sum += a[i][j] * x[j];
            }

            double newValue = (b[i] - sum) / a[i][i];

            error = max(error, fabs(newValue - x[i]));

            x[i] = newValue;
        }

        if (error < tolerance)
            break;
    }

    cout << "\nGauss-Seidel Solution:\n";

    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << x[i] << endl;
}


int main()
{
    int n;
    double a[10][10], b[10];

    cout << "Enter number of equations: ";
    cin >> n;

    cout << "Enter coefficient matrix A:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter constant matrix B:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    // Function calls
    jacobi(a, b, n);
    gaussSeidel(a, b, n);

    return 0;
}