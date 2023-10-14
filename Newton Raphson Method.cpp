//newton raphson method
#include<bits/stdc++.h>
using namespace std;

#define Er 0.0001

//function f(x) = x^2 - 3x + 2

double f(double x)
{

    return x*x-3*x+2;
}

double f_prime(double x)
{

    return 2*x-3;
}

int main()
{
    double x,x1;
    int step=0;

    cout<<"Enter inital value: ";
    cin>>x;

    while(1)
    {
         x1 = x - (f(x))/f_prime(x);

         if(abs(((x1-x)/x1))<=Er)break;
         step++;
         x=x1;

    }

    cout<<"Result: "<<x1<<" after no. of "<<step<<" steps"<<endl;


    return 0;
}
