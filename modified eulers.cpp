//Modified Euler's Method

#include<bits/stdc++.h>
using namespace std;


double df(double x, double y)
{
    double a=x+y;
    return a;
}
int main()
{
    double x0,y0,x,y_i,dy1,dy2,dy_avg,y_n,h;    //for initial values, width, etc.
    cout<<"\nEnter the initial values of x and y respectively:\n";
    cin>>x0>>y0;                    //Initial values
    cout<<"\nEnter the value of x for which you would like to find y:\n";
    cin>>x;
    cout<<"\nEnter the interval width,h:\n";
    cin>>h;                        //input width
    cout<<"x"<<setw(16)<<"y"<<setw(16)<<"hy'"<<setw(16)<<"y_new"<<setw(16)<<"hy_new'"<<setw(16)<<"hy'avg"<<setw(16)<<"y_n+1"<<endl;
    while(fabs(x-x0)>0.0000001)
    {
        dy1=h*df(x0,y0);
        y_i=y0+dy1;
        dy2=h*df(x0+h,y_i);
        dy_avg=(dy1+dy2)/2.0;
        y_n=y0+dy_avg;
        cout<<x0<<setw(16)<<y0<<setw(16);
        cout<<dy1<<setw(16)<<y_i<<setw(16);
        cout<<dy2<<setw(16)<<dy_avg<<setw(16)<<y_n<<endl;
        x0=x0+h;
        y0=y_n;
    }
    cout<<x0<<setw(16)<<y0<<endl;
    cout<<"The approximate value of y at x=0 is "<<y0<<endl;
}
