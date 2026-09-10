#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<double>> a;
vector<double> b;
vector<double> x;
void GaussJordan()
{
    for(int i = 0; i < n; i++)
    {
        // PARTIAL PIVOTING
        // int p = i;
        // for(int j = i + 1; j < n; j++)
        // {
        //     if(fabs(a[j][i]) > fabs(a[p][i]))
        //     {
        //         p = j;
        //     }
        // }
        // // Row Swap
        // if(p != i)
        // {
        //     for(int k = 0; k < n; k++)
        //     {
        //         swap(a[i][k], a[p][k]);
        //     }
        //     swap(b[i], b[p]);
        // }

        // NORMALIZE PIVOT
        double normalized = a[i][i];
        for(int k = 0; k < n; k++)
        {
            a[i][k] = a[i][k] / normalized;
        }
        b[i] = b[i] / normalized;

        // ELIMINATION
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                double pivot = a[j][i] / a[i][i];
                for(int k = 0; k < n; k++)
                {
                    a[j][k] = a[j][k]- pivot * a[i][k];
                }
                b[j] = b[j] - b[i] * pivot;
            }
        }
    }
}

void PrintMatrix()
{
    cout << "\nGauss-Jordan Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "| " << b[i] << endl;
    }
}

void PrintSolution()
{
    cout << "\nSolution:\n";
    cout<< fixed << setprecision(6);
    for(int i = 0; i < n; i++)
    {
        x[i] = b[i];
        cout << "x[" << i << "] = "<< x[i] << endl;
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
    
    GaussJordan();
    PrintMatrix();
    PrintSolution();
    return 0;
}