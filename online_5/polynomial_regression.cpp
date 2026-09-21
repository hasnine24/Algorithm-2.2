#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << fixed << setprecision(3);
    int n;cin>>n;
    vector<double>x(n),y(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    int deg;
    cin>>deg;
    vector<double>sumx(2*(deg+1),0.0);
    for(int i=0;i<=2*deg;i++)
    {
        for(int j=0;j<n;j++)
        {
            sumx[i]=sumx[i]+pow(x[j],i);
        }
    }
    vector<double>sumxy(deg+1,0.0);
    for(int i=0;i<=deg;i++)
    {
        for(int j=0;j<n;j++)
        {
            sumxy[i]=sumxy[i]+(pow(x[j],i)*y[j]);
        }
    }
    vector<vector<double>>A(deg+1,vector<double>(deg+2,0.0));
    for(int i=0;i<=deg;i++)
    {
        for(int j=0;j<=deg;j++)
        {
            A[i][j]=sumx[i+j];
        }
        A[i][deg+1]=sumxy[i];
    }
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
    vector<double> coeff(deg + 1);
    for (int i = deg; i >= 0; i--)
    {
        double value = A[i][deg + 1];
        for (int j = i + 1; j <= deg; j++)
        {
            value = value - A[i][j] * coeff[j];
        }
        coeff[i] = value / A[i][i];
    }
    for (int i = 0; i <= deg; i++)
    {
        cout << coeff[i];
        if(i>0)
        {
            cout<<"*x^"<<i;
        }
        if(i!=deg)
        {
            cout<<"+";
        }
    }
    cout<<endl;
    double xp = 7;
    double yp = coeff[0]+ coeff[1] * xp+ coeff[2] * xp * xp;
    cout << "Predicted performance score at 7 hours: "<< yp << endl;
    return 0;
}