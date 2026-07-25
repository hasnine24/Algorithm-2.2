#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return pow(x,3)+exp(-x)-5*sin(x)-2;
}
double df(double x)
{
    return 3*x*x-exp(-x)-5*cos(x);
}
int main()
{
    double x0=0.5,x1;
    double error,preverror=0;

    int i=1;
    cout<<fixed<<setprecision(8);
    cout<<"Iter\t x0\t\t x1\t\t f(x1)\t\t Sign\t\t f'(x)\t\t Error\t\t Prev Error\n";

    while(true)
    {
        x1=x0-f(x0)/df(x0);

        error=fabs(x1-x0);

        cout<<i<<"\t"
            <<x0<<"\t"
            <<x1<<"\t"
            <<f(x1)<<"\t";

        if(f(x1)>=0)
            cout<<"Positive\t";
        else
            cout<<"Negative\t";

        cout<<df(x1)<<"\t";

        if(i==1)
            cout<<"N/A\t";
        else
            cout<<error<<"\t";

        cout<<preverror<<endl;

        if(error<0.000001)
            break;

        preverror=error;
        x0=x1;
        i++;
    }

    cout<<"\nApproximate Root = "<<x1<<endl;

    return 0;
}
