//Euler's Method

#include<bits/stdc++.h>
using namespace std;


int main()
{

    double x0,h,x,y,n;
    cout<<"Enter x0: ";
    cin>>x0;
    cout<<"Enter x: ";
    cin>>x;
    cout<<"Enter y: ";
    cin>>y;
    cout<<"Enter steps: ";
    cin>>n;
    h=(x-x0)/n;
    for(int i=1;i<=n;i++)
    {
        y=y+h*((y-x)/(y+x));
        cout<<"Y"<<i<<" "<<y<<endl;
        x+=h;
    }

}
