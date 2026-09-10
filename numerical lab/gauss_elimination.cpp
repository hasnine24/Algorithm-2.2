#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<double>> a;
vector<double> b;
vector<double> x;

void BackwardSubstitution()
{
    double sum;
    for(int i = n - 1; i >= 0; i--)
    {
        sum = 0;
        for(int j = n - 1; j > i; j--)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }
}

void PrintUpperTriangular()
{
    cout << "\nUpper Triangular Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<< a[i][j] << " ";
        }
        cout << "| " << b[i] << endl;
    }
}

void PrintSolution()
{
    cout<< fixed << setprecision(6);
    cout << "\nSolution:\n";
    for(int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = "<< x[i] << endl;
    }
}


void ForwardElimination()
{
    double pivot;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            pivot = a[j][i] / a[i][i];
            for(int k = i ; k < n; k++)
            {
                a[j][k] = a[j][k]- pivot * a[i][k];
            }
            b[j] = b[j] - pivot * b[i];
        }
    }
}

void ForwardElimination()
{
    double pivot;
    for(int i = 0; i < n - 1; i++)
    {
        // Partial Pivoting
        int p = i;
        for(int j = i + 1; j < n; j++)
        {
            if(abs(a[j][i]) > abs(a[p][i]))
            {
                p = j;
            }
        }
        // Row Swap
        if(p != i)
        {
            for(int k = 0; k < n; k++)
            {
                swap(a[i][k], a[p][k]);
            }
            swap(b[i], b[p]);
        }
        // Elimination
        for(int j = i + 1; j < n; j++)
        {
            pivot = a[j][i] / a[i][i];

            for(int k = i; k < n; k++)
            {
                a[j][k] = a[j][k]- pivot * a[i][k];
            }
            b[j] = b[j] - b[i] * pivot;
        }
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
    

    ForwardElimination();
    PrintUpperTriangular();
    BackwardSubstitution();
    PrintSolution();
    return 0;
}