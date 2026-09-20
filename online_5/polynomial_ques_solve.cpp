#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << fixed << setprecision(4);
    int n, deg;
    cout << "Number of data: ";
    cin >> n;
    vector<double> x(n), y(n);
    cout << "Data points (x y):" << endl;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    deg = 2;
    // sumX = Σx^i
    vector<double> sumX(2 * deg + 1, 0.0);
    for (int i = 0; i <= 2 * deg; i++)
    {
        for (int j = 0; j < n; j++)
            sumX[i] += pow(x[j], i);
    }
    // sumXY = Σ(x^i * y)
    vector<double> sumXY(deg + 1, 0.0);
    for (int i = 0; i <= deg; i++)
    {
        for (int j = 0; j < n; j++)
            sumXY[i] += pow(x[j], i) * y[j];
    }
    // Matrix
    vector<vector<double>> A(deg + 1,vector<double>(deg + 2, 0.0));
    for (int i = 0; i <= deg; i++)
    {
        for (int j = 0; j <= deg; j++)
            A[i][j] = sumX[i + j];
        A[i][deg + 1] = sumXY[i];
    }
    // Gaussian Elimination
    for (int i = 0; i <= deg; i++)
    {
        for (int j = i + 1; j <= deg; j++)
        {
            double t = A[j][i] / A[i][i];
            for (int k = i; k <= deg + 1; k++)
            {
                A[j][k] = A[j][k] - t * A[i][k];
            }
        }
    }
    // Back Substitution
    vector<double> coeff(deg + 1);
    for (int i = deg; i >= 0; i--)
    {
        coeff[i] = A[i][deg + 1];
        for (int j = i + 1; j <= deg; j++)
        {
            coeff[i] = coeff[i] - A[i][j] * coeff[j];
        }
        coeff[i] = coeff[i] / A[i][i];
    }
    // Coefficients
    cout << endl;
    cout << "Coefficients:" << endl;
    cout << "a = " << coeff[0] << endl;
    cout << "b = " << coeff[1] << endl;
    cout << "c = " << coeff[2] << endl;
    // Polynomial
    cout << endl;
    cout << "Polynomial Regression Equation: ";
    cout << "y = " << coeff[0]<< " + " << coeff[1] << "*x"<< " + " << coeff[2] << "*x^2" << endl;
    // Prediction for x = 7
    double xp = 7;
    double yp = coeff[0]+ coeff[1] * xp+ coeff[2] * xp * xp;
    cout << "Predicted performance score at 7 hours: "<< yp << endl;
    cout << "Fitted polynomial: y = ";
    for (int i = 0; i <= deg; i++)
    {
        cout << coeff[i];
        if (i > 0)
            cout << "*x^" << i;
        if (i != deg)
            cout << " + ";
    }
    return 0;
}