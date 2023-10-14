//Modified Euler's Method

#include<bits/stdc++.h>
using namespace std;

float df(float x,float y){
        float a=x*x+y;
        return a;
}

int main()
{
        cout<<"Enter initial value : ";
        float x0,x1,y0,x2;
        cin>>x0>>y0;
        cout<<"Enter final value of x : ";
        cin>>x1;
        float h=x1-x0;
        float y1,y2,y3,y4,y5,y6,y7,y8;
        y1=y0+h*df(x0,y0);
        y2=y0+h/2*(df(x0,y0)+df(x1,y1));
        while(fabs(y2-y1)>0.00000001){
                y1=y2;
                y2=y0+h/2*(df(x0,y0)+df(x1,y1));
        }
        cout<<"Value oy y1("<<x0<<") is : "<<y1<<'\n';
        y2=y1+h*df(x1,y1);
        x2=x1+h;
        y3=y1+h/2*(df(x1,y1)+df(x2,y2));
        while(fabs(y3-y2)>0.00000001){
                y2=y3;
                y3=y1+h/2*(df(x1,y1)+df(x2,y2));
        }
        cout<<"Value of y2("<<x0+h<<") is : "<<y3<<'\n';
}
