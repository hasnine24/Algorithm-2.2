#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// g(x)
double g(double x)
{
    return (7*x*x - 2*x*x*x - 1)/4.0;
}

// Horner's Method
double horner(double a[], int degree, double x)
{
    double result = a[0];

    for(int i=1;i<=degree;i++)
        result = result*x + a[i];

    return result;
}

int main()
{
    // Original Polynomial
    double poly[] = {2,-7,4,1};

    // Initial Guess
    double x0 = -poly[1]/poly[0]; // 3.5
    double x1;

    int iter=1;

    cout<<fixed<<setprecision(6);

    cout<<"Initial Guess = "<<x0<<endl<<endl;

    cout<<"Iter\t"
        <<"x0\t\t"
        <<"x1\t\t"
        <<"Relative Error"<<endl;

    while(true)
    {
        x1 = g(x0);

        double error = fabs((x1-x0)/x1);

        cout<<iter<<"\t"
            <<x0<<"\t"
            <<x1<<"\t"
            <<error<<endl;

        if(error<0.000001)
            break;

        x0=x1;
        iter++;
    }

    cout<<"\nApproximate Root = "<<x1<<endl;

    cout<<"Original Polynomial Value = "
        <<horner(poly,3,x1)<<endl;

    return 0;
}
