#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<double>> a;
vector<double> b;
vector<double> x;
// ================= JACOBI =================
void Jacobi()
{
    cout << "\nJacobi Method\n";
    cout << fixed << setprecision(6);
    int iteration = 1;
    double sum;
    double tolerance = 0.0001;
    vector<double> temp(n, 0);
    while(iteration <= 15)
    {
        temp = x;
        double maxError = 0;
        cout << "Iteration = " << iteration << "\t";
        for(int i = 0; i < n; i++)
        {
            sum = 0;
            for(int j = 0; j < n; j++)
                if(i != j)
                    sum += a[i][j] * temp[j];

            x[i] = (b[i] - sum) / a[i][i];
            double error = abs(x[i] - temp[i]);

            if(error > maxError)
                maxError = error;

            cout << "x[" << i << "] = "<< x[i] << "\t";
        }
        cout << "Max Error = " << maxError << endl;

        if(maxError < tolerance)
        {
            break;
        }
        iteration++;
    }
}
// ================= GAUSS SEIDEL =================
void GaussSeidel()
{
    cout << "\nGauss-Seidel Method\n";
    cout << fixed << setprecision(6);
    int iteration = 1;
    double sum;
    double tolerance = 0.0001;
    while(iteration <= 15)
    {
        vector<double> temp = x;
        double maxError = 0;
        cout << "Iteration = " << iteration << "\t";
        for(int i = 0; i < n; i++)
        {
            sum = 0;
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    sum += a[i][j] * x[j];
                }
            }
            // New value immediately used
            x[i] = (b[i] - sum) / a[i][i];
            double error = abs(x[i] - temp[i]);
            if(error > maxError)
            {
                maxError = error;
            }
            cout << "x[" << i << "] = "<< x[i] << "\t";
        }
        cout << "Max Error = " << maxError << endl;
        if(maxError < tolerance)
        {
            break;
        }
        iteration++;
    }
}

int main()
{
    cin >> n;
    a = vector<vector<double>>(n, vector<double>(n, 0));
    b = vector<double>(n, 0);
    x = vector<double>(n, 0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        cin >> b[i];
      
    Jacobi();


    for(int i = 0; i < n; i++)
        x[i] = 0;

    GaussSeidel();
    return 0;
}